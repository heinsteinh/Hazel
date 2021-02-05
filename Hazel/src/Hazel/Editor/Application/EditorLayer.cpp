#include "EditorLayer.h"

#include "imgui.h"

#include "Hazel/Core/Logging/Log.h"
#include "Hazel/Rendering/Textures/TextureFactory.h"
#include "Hazel/Tests/TestCameraController.h"
#include "Hazel/Tests/TestParticles.h"
#include "EditorViewport.h"
#include "Hazel/Scene/Serialization/SceneSerializer.h"

namespace Hazel
{
	EditorLayer::EditorLayer()
		: Layer("Hazel Editor")
	{
	}

	void EditorLayer::OnAttach()
	{
		auto &graphicsContext = GetGraphicsContext();

		framebuffer = graphicsContext.CreateFramebuffer({{GetWindow().GetSize()}});

		rendererInfo.GraphicsContext = &graphicsContext;
		rendererInfo.TextureSlotCount = graphicsContext.GetTextureSlotCount();
		sceneManager.OnAttach(*this, rendererInfo);

		scene = sceneManager.CreateScene("Test");

		auto &renderer = sceneManager.GetRenderer();
		auto &assetManager = sceneManager.GetAssetManager();

		auto spriteSheet = TextureFactory::CreateTextureFromFile(
			graphicsContext,
			R"(C:\Users\christian\source\repos\Hazel\Editor\assets\textures\SpriteSheet.png)");

		assetManager.AddTexture(spriteSheet);
		assetManager.AddScriptFactory<TestCameraController>("TestCameraController");
		assetManager.AddScriptFactory<TestParticles>("TestParticles");

		auto square1 = scene->CreateEntity();
		square1.AddComponent<TagComponent>("Square1");
		square1.AddComponent<SpriteComponent>().Material.Texture = assetManager.GetTexture("SpriteSheet");
		square1.AddComponent<TransformComponent>().Transform.Scale.x = spriteSheet->GetAspectRatio();

		auto square2 = scene->CreateEntity();
		square2.AddComponent<TagComponent>("Square2");
		square2.AddComponent<SpriteComponent>();
		square2.AddComponent<TransformComponent>();

		camera1 = scene->CreateEntity();
		camera1.AddComponent<TagComponent>("Camera1");
		camera1.AddComponent<TransformComponent>();
		camera1.AddComponent<NativeScriptComponent>(assetManager.CreateScript("TestCameraController"));
		camera1.AddComponent<CameraComponent>();

		scene->SetPrimaryCamera(camera1);

		camera2 = scene->CreateEntity();
		camera2.AddComponent<TagComponent>("Camera2");
		camera2.AddComponent<TransformComponent>().Transform.Translation.x = 1.0f;
		camera2.AddComponent<CameraComponent>();

		auto particleEmitter = scene->CreateEntity();
		particleEmitter.AddComponent<TagComponent>("Particle Emitter");
		particleEmitter.AddComponent<TransformComponent>().Transform.Translation.z += 0.1f;
		particleEmitter.AddComponent<ParticleComponent>();
		particleEmitter.AddComponent<NativeScriptComponent>(assetManager.CreateScript("TestParticles"));

		sceneManager.OnPlay(*scene);

		fileDialog.SetWindow(&GetWindow());
		fileDialog.SetFilters({{"YAML files", "*.yaml"}});
	}

	void EditorLayer::OnDetach()
	{
	}

	void EditorLayer::OnUpdate()
	{
		if (viewport.IsEmpty())
		{
			return;
		}

		sceneManager.OnUpdate(*scene);

		GetGraphicsContext().Clear(framebuffer);
		sceneManager.OnRender(*scene, framebuffer);
	}

	void EditorLayer::OnGui()
	{
		editorWindow.Begin("Hazel");

		menu.Draw();
		if (menu.WantQuit())
		{
			CloseApplication();
		}
		if (menu.WantOpen() && fileDialog.GetOpenFilename())
		{
			SceneSerializer::Deserialize(*scene, fileDialog.GetFilename());
			sceneManager.OnPlay(*scene);
		}
		if (menu.WantSave() && fileDialog.GetSaveFilename())
		{
			SceneSerializer::Serialize(*scene, fileDialog.GetFilename());
		}

		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, {0.0f, 0.0f});
		ImGui::Begin("Viewport");

		EnableGuiKeyboardFilter(!ImGui::IsWindowFocused());
		EnableGuiMouseFilter(!ImGui::IsWindowHovered());

		auto newViewport = EditorViewport::GetViewport(GetWindow());
		auto viewportSize = newViewport.GetSize();
		if (newViewport != viewport)
		{
			viewport = newViewport;

			Log::Warn("New viewport size: {} {}", viewportSize.x, viewportSize.y);
			if (!viewport.IsEmpty())
			{
				framebuffer = GetGraphicsContext().CreateFramebuffer({viewportSize});
			}
			sceneManager.OnViewportResize(*scene, newViewport);
			OnUpdate();
		}

		ImGui::Image(
			framebuffer->GetColorAttachment().GetHandle(),
			{viewportSize.x, viewportSize.y},
			{0.0f, 1.0f},
			{1.0f, 0.0f});

		ImGui::End();
		ImGui::PopStyleVar();

		ImGui::Begin("Test");
		if (ImGui::Checkbox("Camera 1", &useCamera1))
		{
			scene->SetPrimaryCamera(useCamera1 ? camera1 : camera2);
		}
		ImGui::End();

		ImGui::Begin("Settings");
		fpsPanel.Draw(GetDeltaTime());
		rendererStatisticsPanel.Draw(sceneManager.GetRenderer().GetStatistics());
		if (batchPanel.Draw(rendererInfo))
		{
			sceneManager.ResetRenderer(rendererInfo);
		}
		ImGui::End();

		scenePanel.Draw("Scene Hierarchy", *scene);

		editorWindow.End();
	}

	void EditorLayer::OnEvent(Event &e)
	{
		sceneManager.OnEvent(*scene, e);
	}
}