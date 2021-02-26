#include "EditorLayer.h"

#include "imgui.h"

#include "Hazel/Core/Logging/Log.h"
#include "Hazel/Rendering/Textures/TextureFactory.h"
#include "Hazel/Tests/TestCameraController.h"
#include "Hazel/Tests/TestParticles.h"
#include "Hazel/Scene/Serialization/SceneSerializer.h"
#include "Hazel/Scene/Components/TagComponent.h"
#include "Hazel/Scene/Components/TransformComponent.h"
#include "Hazel/Scene/Components/SpriteComponent.h"
#include "Hazel/Scene/Components/NativeScriptComponent.h"
#include "Hazel/Editor/Viewport/EditorWindow.h"
#include "Hazel/Editor/Viewport/EditorMenu.h"
#include "Hazel/Editor/Viewport/EditorViewport.h"
#include "Hazel/Editor/Utils/FpsPanel.h"
#include "Hazel/Editor/Utils/BatchPanel.h"
#include "Hazel/Editor/Utils/RendererStatisticsPanel.h"
#include "Hazel/Editor/ScenePanels/SceneHierarchyPanel.h"

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

		std::string testFilename = R"(C:\Users\christian\source\repos\Hazel\Editor\assets\textures\SpriteSheet.png)";

		auto spriteSheet = TextureFactory::CreateTextureFromFile(graphicsContext, testFilename);

		assetManager.AddTexture(spriteSheet);
		assetManager.AddScriptFactory<TestCameraController>("TestCameraController");
		assetManager.AddScriptFactory<TestParticles>("TestParticles");

		auto square1 = scene->CreateEntity();
		square1.AddComponent<TagComponent>("Square1");
		square1.AddComponent<SpriteComponent>().Material.Texture = assetManager.GetTexture(testFilename);
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

		scene->SetCameraEntity(camera1);

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
		EditorWindow::Begin("Hazel");

		auto status = EditorMenu::Draw(GetInput());
		if (status.Quit)
		{
			CloseApplication();
		}
		if (status.Open && fileDialog.GetOpenFilename())
		{
			SceneSerializer::Deserialize(*scene, fileDialog.GetFilename());
			sceneManager.OnPlay(*scene);
		}
		if (status.Save && fileDialog.GetSaveFilename())
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
			scene->SetCameraEntity(useCamera1 ? camera1 : camera2);
		}
		ImGui::End();

		ImGui::Begin("Settings");
		FpsPanel::Draw(GetDeltaTime());
		RendererStatisticsPanel::Draw(sceneManager.GetRenderer().GetStatistics());
		if (BatchPanel::Draw(rendererInfo))
		{
			sceneManager.ResetRenderer(rendererInfo);
		}
		ImGui::End();

		SceneHierarchyPanel::Draw("Scene Hierarchy", *scene, selectedEntity);

		EditorWindow::End();
	}

	void EditorLayer::OnEvent(Event &e)
	{
		sceneManager.OnEvent(*scene, e);
	}
}