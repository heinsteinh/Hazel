#include "EditorLayer.h"

#include "imgui.h"

#include "Hazel/Core/Logging/Log.h"
#include "Hazel/Rendering/Textures/TextureFactory.h"
#include "Hazel/Tests/TestCameraController.h"
#include "Hazel/Tests/TestParticles.h"
#include "Hazel/Scene/SceneManager/DefaultSceneManager.h"
#include "Hazel/Scene/Rendering/SceneRenderer.h"
#include "Hazel/Scene/Update/SceneUpdater.h"
#include "Hazel/Scene/Serialization/SceneSerializer.h"
#include "Hazel/Editor/Viewport/EditorWindow.h"
#include "Hazel/Editor/Viewport/EditorMenu.h"
#include "Hazel/Editor/Viewport/EditorViewport.h"
#include "Hazel/Editor/Utils/FpsPanel.h"
#include "Hazel/Editor/Utils/BatchPanel.h"
#include "Hazel/Editor/Utils/RendererStatisticsPanel.h"
#include "Hazel/Editor/Widgets/ImageView.h"
#include "Hazel/Editor/ScenePanels/SceneHierarchyPanel.h"

namespace Hazel
{
	EditorLayer::EditorLayer()
		: ApplicationLayer("Hazel Editor")
	{
	}

	void EditorLayer::OnAttach()
	{
		auto application = GetApplication();
		auto &window = application.GetWindow();
		auto &graphicsContext = application.GetGraphicsContext();

		FramebufferInfo framebufferInfo;
		framebufferInfo.Size = window.GetSize();
		framebuffer = graphicsContext.CreateFramebuffer(framebufferInfo);

		rendererInfo.GraphicsContext = &graphicsContext;
		rendererInfo.TextureSlotCount = graphicsContext.GetTextureSlotCount();
		sceneManager = DefaultSceneManager::Create(*this, rendererInfo);

		scene = std::make_shared<Scene>("Test");

		auto &assetManager = sceneManager->GetAssetManager();

		std::string testFilename = R"(C:\Users\christian\source\repos\Hazel\Editor\assets\textures\SpriteSheet.png)";

		TextureFactory textureFactory(graphicsContext);
		auto spriteSheet = textureFactory.TryCreateTextureFromFile(testFilename);
		assetManager.AddTexture(spriteSheet);

		assetManager.AddScriptFactory("TestCameraController", []()
		{
			return std::make_unique<TestCameraController>();
		});
		assetManager.AddScriptFactory("TestParticles", []()
		{
			return std::make_unique<TestParticles>();
		});

		auto square1 = scene->CreateEntity("Square1");
		square1.AddComponent<SpriteComponent>().Material.Texture = assetManager.GetTexture(testFilename);
		square1.GetTransform().Scale.x = spriteSheet->GetAspectRatio();

		auto square2 = scene->CreateEntity("Square2");
		square2.AddComponent<SpriteComponent>();

		camera1 = scene->CreateEntity("Camera1");
		camera1.AddComponent<ScriptComponent>(assetManager.CreateScript("TestCameraController"));
		camera1.AddComponent<CameraComponent>();

		scene->SetCameraEntity(camera1);

		camera2 = scene->CreateEntity("Camera2");
		camera2.GetTransform().Translation.x = 1.0f;
		camera2.AddComponent<CameraComponent>();

		auto particleEmitter = scene->CreateEntity("Particle Emitter");
		particleEmitter.GetTransform().Translation.z += 0.1f;
		particleEmitter.AddComponent<ParticleComponent>();
		particleEmitter.AddComponent<ScriptComponent>(assetManager.CreateScript("TestParticles"));

		SceneUpdater updater(*sceneManager);
		updater.OnPlay(*scene);

		fileDialog.SetWindow(&window);
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

		SceneUpdater updater(*sceneManager);
		updater.OnUpdate(*scene);

		GetApplication().GetGraphicsContext().Clear(framebuffer);

		SceneRenderer renderer(*sceneManager);
		renderer.RenderScene(*scene);
	}

	void EditorLayer::OnGui()
	{
		EditorWindow::Begin("Hazel");

		auto &application = GetApplication();
		auto &settings = application.GetSettings();

		auto status = EditorMenu::Draw(GetInput());
		if (status.Quit)
		{
			settings.Running = false;
		}
		if (status.Open && fileDialog.GetOpenFilename())
		{
			SceneSerializer serializer(*sceneManager);
			serializer.Deserialize(*scene, fileDialog.GetFilename());

			SceneUpdater updater(*sceneManager);
			updater.OnPlay(*scene);
		}
		if (status.Save && fileDialog.GetSaveFilename())
		{
			SceneSerializer serializer(*sceneManager);
			serializer.Serialize(*scene, fileDialog.GetFilename());
		}

		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, {0.0f, 0.0f});
		ImGui::Begin("Viewport");

		settings.GuiKeyboardFilterEnabled = !ImGui::IsWindowFocused();
		settings.GuiMouseFilterEnabled = !ImGui::IsWindowHovered();

		auto newViewport = EditorViewport::GetViewport(application.GetWindow());
		auto viewportSize = newViewport.GetSize();
		if (newViewport != viewport)
		{
			viewport = newViewport;

			Log::Warn("New viewport size: {} {}", viewportSize.x, viewportSize.y);
			if (!viewport.IsEmpty())
			{
				framebuffer = application.GetGraphicsContext().CreateFramebuffer({viewportSize});
				sceneManager->GetRenderer().SetFramebuffer(framebuffer);
			}

			SceneUpdater updater(*sceneManager);
			updater.OnViewportResize(*scene, newViewport);
			OnUpdate();
		}

		ImageView::Draw(framebuffer->GetColorAttachment().GetHandle(), viewportSize);

		ImGui::End();
		ImGui::PopStyleVar();

		ImGui::Begin("Test");
		if (ImGui::Checkbox("Camera 1", &useCamera1))
		{
			scene->SetCameraEntity(useCamera1 ? camera1 : camera2);
		}
		ImGui::End();

		ImGui::Begin("Settings");
		FpsPanel::Draw(application.GetDeltaTime());
		RendererStatisticsPanel::Draw(sceneManager->GetRenderer().GetStatistics());
		if (BatchPanel::Draw(rendererInfo))
		{
			sceneManager->ResetRenderer(rendererInfo);
		}
		ImGui::End();

		SceneHierarchyPanel scenePanel(*sceneManager);
		scenePanel.Draw("Scene Hierarchy", *scene, selectedEntity);

		EditorWindow::End();
	}

	void EditorLayer::OnEvent(Event &e)
	{
		SceneUpdater updater(*sceneManager);
		updater.OnEvent(*scene, e);
	}
}