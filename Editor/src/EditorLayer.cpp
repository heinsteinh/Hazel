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

		BatchInfo rendererInfo;
		rendererInfo.MaxIndexCount = maxIndices;
		rendererInfo.MaxVertexCount = maxVertices;
		rendererInfo.MaxTextureSlotCount = graphicsContext.GetMaxTextureSlotCount();
		renderer = std::make_shared<Renderer2D>(graphicsContext, rendererInfo);

		framebuffer = graphicsContext.CreateFramebuffer({GetWindow().GetSize()});

		squareMesh = SquareMesh::CreateMesh();

		spriteSheet = TextureBuilder::CreateTextureFromFile(
			GetGraphicsContext(),
			"assets\\textures\\SpriteSheet.png");

		cameraController.OnAttach(camera, GetWindow().GetSize());

		square = scene.CreateEntity();
		auto &drawData = square.AddComponent<DrawData>();
		drawData.Mesh = squareMesh;
		drawData.Mesh->SetColor({1.0f, 1.0f, 1.0f, 1.0f});
		drawData.Texture = spriteSheet;
		drawData.Transform.Scale = {spriteSheet.GetAspectRatio(), 1.0f, 1.0f};
	}

	void EditorLayer::OnDetach()
	{
	}

	void EditorLayer::OnUpdate(float deltaTime)
	{
		renderTime = deltaTime;

		cameraController.OnUpdate(camera, GetInput(), deltaTime);

		auto &drawData = square.GetComponent<DrawData>();
		drawData.Texture.SetRegion(Rectangle::FromBottomLeftAndSize(bottomLeft, size));

		GetGraphicsContext().SetFramebuffer(framebuffer);
		GetGraphicsContext().Clear();
		renderer->BeginScene(camera.GetViewProjectionMatrix());
		for (auto entity : scene.GetAllEntitiesWith<DrawData>())
		{
			HZ_ASSERT(entity.HasComponent<DrawData>(), "test");
			auto &test = entity.GetComponent<DrawData>();
			renderer->Render(test);
		}
		renderer->EndScene();
		GetGraphicsContext().SetFramebuffer(nullptr);
	}

	void EditorLayer::OnImGuiRender()
	{
		dockspace.Begin();

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
		if (newSize != framebuffer->GetSize())
		{
			Log::Debug("New viewport size: {} {}", newSize.x, newSize.y);
			WindowResizeEvent e(newSize.x, newSize.y);
			framebuffer = GetGraphicsContext().CreateFramebuffer({newSize});
			cameraController.OnEvent(camera, e);
			renderer->OnEvent(e);
		}

		ImGui::Image(
			framebuffer->GetColorAttachment()->GetHandle(),
			viewportSize,
			{0.0f, 1.0f},
			{1.0f, 0.0f});

		ImGui::End();
		ImGui::PopStyleVar();

		ImGui::Begin("Info");
		ImGui::Text("Update Time: %fms (%fFPS)", 1000 * renderTime, 1.0f / renderTime);
		ImGui::Text("Camera Position: %f %f %f", camera.GetPosition().x, camera.GetPosition().y, camera.GetZoomLevel());
		ImGui::Text("Camera Rotation: %fdeg", glm::degrees(camera.GetRotation()));
		ImGui::End();

		auto &drawData = square.GetComponent<DrawData>();
		ImGui::Begin("Transform");
		ImGui::SliderFloat2("Translation", glm::value_ptr(drawData.Transform.Position), -10.0f, 10.0f);
		ImGui::SliderFloat("Rotation", &drawData.Transform.Angle, 0.0f, glm::radians(360.0f));
		ImGui::SliderFloat2("Scale", glm::value_ptr(drawData.Transform.Scale), 0.0f, glm::radians(360.0f));
		ImGui::End();

		ImGui::Begin("Texture Coordinates");
		ImGui::SliderFloat("Left", &bottomLeft.x, 0.0f, 2560.0f);
		ImGui::SliderFloat("Bottom", &bottomLeft.y, 0.0f, 1664.0f);
		ImGui::SliderFloat("Width", &size.x, 0.0f, 2560.0f);
		ImGui::SliderFloat("Height", &size.y, 0.0f, 1664.0f);
		ImGui::End();

		ImGui::Begin("Renderer");
		ImGui::SliderInt("MaxVertices", &maxVertices, 0, 100000);
		ImGui::SliderInt("MaxIndices", &maxIndices, 0, 100000);
		ImGui::Text("DrawCall: %zu", renderer->GetStatistics().DrawCallCount);
		ImGui::Text("VertexCount: %zu", renderer->GetStatistics().VertexCount);
		ImGui::Text("IndexCount: %zu", renderer->GetStatistics().IndexCount);
		ImGui::Text("TextureCount: %zu", renderer->GetStatistics().TextureCount);
		if (ImGui::Button("Reset"))
		{
			OnAttach();
		}
		ImGui::End();

		dockspace.End();
	}

	void EditorLayer::OnEvent(Event &e)
	{
		if (e.GetType() == EventType::WindowResize)
		{
			e.Discard();
			return;
		}
		cameraController.OnEvent(camera, e);
		renderer->OnEvent(e);
		e.Dispatch([this](KeyPressEvent &e)
		{
			if (e.GetKey() == Key::Backspace)
			{
				camera = {};
				cameraController.OnAttach(camera, framebuffer->GetSize());
			}
		});
	}
}