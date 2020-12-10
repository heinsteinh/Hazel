#include "EditorLayer.h"

#include "imgui.h"

#include "Hazel/Textures/TextureBuilder.h"
#include "Hazel/Rendering/SquareMesh.h"
#include "Hazel/Logging/Log.h"

namespace Hazel
{
	EditorLayer::EditorLayer()
		: Layer("Hazel Editor")
	{
	}

	void EditorLayer::OnAttach()
	{
		auto &graphicsContext = GetGraphicsContext();

		rendererInfo.MaxIndexCount = 10000;
		rendererInfo.MaxVertexCount = 40000;
		rendererInfo.MaxTextureSlotCount = graphicsContext.GetMaxTextureSlotCount();
		renderer = std::make_shared<Renderer2D>(graphicsContext, rendererInfo);

		framebuffer = graphicsContext.CreateFramebuffer({{GetWindow().GetSize()}});

		spriteSheet = TextureBuilder::CreateTextureFromFile(
			GetGraphicsContext(),
			"assets\\textures\\SpriteSheet.png");
		region = spriteSheet.GetRegion();

		SceneInfo sceneInfo;
		sceneInfo.Layer = this;
		sceneInfo.Renderer = renderer.get();
		scene = std::make_shared<Scene>(sceneInfo);

		square = scene->CreateEntity();
		square.AddComponent<SpriteComponent>();
		square.AddComponent<TransformComponent>().Transform.Scale.x = spriteSheet.GetRegion().GetAspectRatio();
		square.AddComponent<TextureComponent>(spriteSheet);

		camera1 = scene->CreateEntity();
		camera1.AddComponent<TransformComponent>();
		camera1.AddComponent<NativeScriptComponent>(std::make_shared<CameraControllerScript>());
		camera1.AddComponent<CameraComponent>();

		scene->SetMainCamera(camera1);

		camera2 = scene->CreateEntity();
		camera2.AddComponent<TransformComponent>().Transform.Translation.x = 1.0f;
		camera2.AddComponent<CameraComponent>();

		auto particleEmitter = scene->CreateEntity();
		particleEmitter.AddComponent<ParticleSourceComponent>();
		particleEmitter.AddComponent<NativeScriptComponent>(std::make_shared<ParticleScript>());
	}

	void EditorLayer::OnDetach()
	{
	}

	void EditorLayer::OnUpdate()
	{
		if (Size::IsEmpty(viewport))
		{
			return;
		}

		SubTexture &texture = square.GetComponent<TextureComponent>().Texture;
		texture.SetRegion(region);

		scene->OnUpdate();

		GetGraphicsContext().SetFramebuffer(framebuffer.get());
		GetGraphicsContext().Clear();
		scene->OnRender();
		GetGraphicsContext().SetFramebuffer(nullptr);
	}

	void EditorLayer::OnImGuiRender()
	{
		editorWindow.Begin();

		scene->OnImGuiRender();

		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, {0.0f, 0.0f});
		ImGui::Begin("Viewport");

		bool blockKeyboard = !ImGui::IsWindowFocused();
		bool blockMouse = !ImGui::IsWindowHovered();
		EnableImGuiKeyboardFilter(blockKeyboard);
		EnableImGuiMouseFilter(blockMouse);

		auto viewportSize = ImGui::GetContentRegionAvail();
		auto windowPosition = ImGui::GetWindowPos();
		glm::vec2 newSize = {viewportSize.x, viewportSize.y};
		glm::vec2 newPosition = {windowPosition.x, windowPosition.y};
		if (!Size::IsEmpty(newSize) && (newSize != viewport || newPosition != position))
		{
			viewport = newSize;
			position = newPosition;

			auto newViewport = Rectangle::FromBottomLeftAndSize(
				position - GetWindow().GetPosition(),
				viewport);

			Log::Warn("New viewport size: {} {}", viewport.x, viewport.y);
			Log::Warn("New window position: {} {}", position.x, position.y);
			framebuffer = GetGraphicsContext().CreateFramebuffer({viewport});
			scene->OnViewportResize(newViewport);
			OnUpdate();
		}

		ImGui::Image(
			framebuffer->GetColorAttachment()->GetHandle(),
			viewportSize,
			{0.0f, 1.0f},
			{1.0f, 0.0f});

		ImGui::End();
		ImGui::PopStyleVar();

		infoPanel.Draw("Info", *this);
		transformPanel.Draw("Camera", camera1.GetComponent<TransformComponent>().Transform);
		transformPanel.Draw("Transform", square.GetComponent<TransformComponent>().Transform);

		textureRegionPanel.Draw("Texture Coordinates", region, spriteSheet.GetSource()->GetSize());

		rendererInfoPanel.Draw("Renderer Info", rendererInfo, renderer->GetStatistics());
		/*if (rendererInfoPanel.WantReset())
		{
			renderer = std::make_shared<Renderer2D>(GetGraphicsContext(), rendererInfo);
		}*/

		editorWindow.End();

		if (!editorWindow.IsOpen())
		{
			Quit();
		}
	}

	void EditorLayer::OnEvent(Event &e)
	{
		scene->OnEvent(e);
	}
}