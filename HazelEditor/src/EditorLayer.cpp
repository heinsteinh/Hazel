#include "EditorLayer.h"

#include "imgui.h"

#include "Hazel/Textures/TextureBuilder.h"
#include "Hazel/Rendering/SquareMesh.h"
#include "Hazel/Logging/Log.h"

namespace Hazel
{
	EditorLayer::EditorLayer()
		: Layer("Hazel Editor"),
		drawData({SquareMesh::CreateMesh()})
	{
	}

	void EditorLayer::OnAttach()
	{
		auto &graphicsContext = GetGraphicsContext();

		RendererInfo rendererInfo;
		rendererInfo.GraphicsContext = &graphicsContext;
		rendererInfo.MaxIndexCount = maxIndices;
		rendererInfo.MaxVertexCount = maxVertices;
		renderer = std::make_shared<Renderer2D>(rendererInfo);

		framebuffer = graphicsContext.CreateFramebuffer({GetWindow().GetSize()});

		spriteSheet = TextureBuilder::CreateTextureFromFile(
			GetGraphicsContext(),
			"assets\\textures\\SpriteSheet.png");

		drawData.Mesh->SetColor({1.0f, 1.0f, 1.0f, 1.0f});
		drawData.Texture = spriteSheet;
		drawData.Transform.SetScale({spriteSheet->GetAspectRatio(), 1.0f});

		camera.SetAspectRatio(GetWindow().GetAspectRatio());
	}

	void EditorLayer::OnDetach()
	{
	}

	void EditorLayer::OnUpdate(float deltaTime)
	{
		renderTime = deltaTime;

		cameraController.UpdateCamera(camera, GetInput(), deltaTime);

		drawData.Texture.SetRegion(Rectangle::FromBottomLeftAndSize(bottomLeft, size));

		GetGraphicsContext().SetFramebuffer(framebuffer);
		GetGraphicsContext().Clear();
		renderer->BeginScene(camera);
		renderer->Render(drawData);
		renderer->EndScene();
		GetGraphicsContext().SetFramebuffer(nullptr);
	}

	void EditorLayer::OnImGuiRender()
	{
		dockspace.Begin();

		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, {0.0f, 0.0f});
		ImGui::Begin("Scene");
		auto viewportSize = ImGui::GetContentRegionAvail();
		Size newSize = {viewportSize.x, viewportSize.y};
		if (newSize != framebuffer->GetSize())
		{
			Log::Debug("New viewport size: {} {}", newSize.Width, newSize.Height);
			framebuffer = GetGraphicsContext().CreateFramebuffer({newSize});
			cameraController.UpdateCamera(camera, WindowResizeEvent(newSize.Width, newSize.Height));
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

		ImGui::Begin("Transform");
		ImGui::SliderFloat2("Translation", glm::value_ptr(drawData.Transform.Position), -10.0f, 10.0f);
		ImGui::SliderFloat("Rotation", &drawData.Transform.Angle, 0.0f, glm::radians(360.0f));
		ImGui::SliderFloat2("Scale", glm::value_ptr(drawData.Transform.Scale), 0.0f, glm::radians(360.0f));
		ImGui::End();

		ImGui::Begin("Texture Coordinates");
		ImGui::SliderFloat("Left", &bottomLeft.x, 0.0f, 2560.0f);
		ImGui::SliderFloat("Bottom", &bottomLeft.y, 0.0f, 1664.0f);
		ImGui::SliderFloat("Width", &size.Width, 0.0f, 2560.0f);
		ImGui::SliderFloat("Height", &size.Height, 0.0f, 1664.0f);
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
		cameraController.UpdateCamera(camera, e);
		e.Dispatch([this](KeyPressEvent &e)
		{
			if (e.GetKey() == Key::Backspace)
			{
				camera = {};
				camera.SetAspectRatio(GetWindow().GetAspectRatio());
			}
		});
	}
}