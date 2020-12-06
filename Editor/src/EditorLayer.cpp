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

		squareMesh = SquareMesh::CreateMesh();

		spriteSheet = TextureBuilder::CreateTextureFromFile(
			GetGraphicsContext(),
			"assets\\textures\\SpriteSheet.png");
		region = spriteSheet.GetRegion();

		scene.SetRenderer(*renderer);
		scene.SetLayer(*this);

		square = scene.CreateEntity();
		square.AddComponent<SpriteComponent>();
		square.AddComponent<TransformComponent>().Transform.Scale.x = spriteSheet.GetRegion().GetAspectRatio();
		square.AddComponent<TextureComponent>(spriteSheet);

		camera1 = scene.CreateEntity();
		camera1.AddComponent<TransformComponent>();
		camera1.AddComponent<NativeScriptComponent>(std::make_shared<CameraControllerScript>());
		camera1.AddComponent<CameraComponent>();

		scene.SetMainCamera(camera1);

		camera2 = scene.CreateEntity();
		camera2.AddComponent<TransformComponent>().Transform.Translation.x = 1.0f;
		camera2.AddComponent<CameraComponent>();
	}

	void EditorLayer::OnDetach()
	{
	}

	void EditorLayer::OnUpdate()
	{
		SubTexture &texture = square.GetComponent<TextureComponent>().Texture;
		texture.SetRegion(region);

		GetGraphicsContext().SetFramebuffer(framebuffer.get());
		GetGraphicsContext().Clear();
		scene.OnUpdate();
		GetGraphicsContext().SetFramebuffer(nullptr);
	}

	void EditorLayer::OnImGuiRender()
	{
		editorWindow.Begin();

		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, {0.0f, 0.0f});
		ImGui::Begin("Viewport");

		bool blockKeyboard = !ImGui::IsWindowFocused();
		bool blockMouse = !ImGui::IsWindowHovered();
		EnableImGuiKeyboardFilter(blockKeyboard);
		EnableImGuiMouseFilter(blockMouse);
		if (!this->blockKeyboard && blockKeyboard)
		{
			GetInput().ClearKeys();
		}
		if (!this->blockMouse && blockMouse)
		{
			GetInput().ClearMouseButtons();
		}
		this->blockKeyboard = blockKeyboard;
		this->blockMouse = blockMouse;

		auto viewportSize = ImGui::GetContentRegionAvail();
		glm::vec2 newSize = {viewportSize.x, viewportSize.y};
		if (newSize != viewport)
		{
			viewport = newSize;
			Log::Debug("New viewport size: {} {}", viewport.x, viewport.y);
			framebuffer = GetGraphicsContext().CreateFramebuffer({viewport});
			scene.OnViewportResize(viewport);
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
		if (rendererInfoPanel.WantReset())
		{
			renderer = std::make_shared<Renderer2D>(GetGraphicsContext(), rendererInfo);
			scene.SetRenderer(*renderer);
		}

		editorWindow.End();

		if (!editorWindow.IsOpen())
		{
			Quit();
		}
	}

	void EditorLayer::OnEvent(Event &e)
	{
		scene.OnEvent(e);
	}
}