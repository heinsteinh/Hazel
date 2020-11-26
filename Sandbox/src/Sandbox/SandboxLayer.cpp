#include "SandboxLayer.h"

#include "imgui.h"

#include "Hazel/Textures/TextureBuilder.h"
#include "Hazel/Rendering/SquareMesh.h"

namespace Sandbox
{
	SandboxLayer::SandboxLayer()
		: Layer("Sandbox"),
		drawData({Hazel::SquareMesh::CreateMesh()})
	{
	}

	void SandboxLayer::OnAttach()
	{
		Hazel::RendererInfo rendererInfo;
		rendererInfo.GraphicsContext = &GetGraphicsContext();
		rendererInfo.MaxIndexCount = maxIndices;
		rendererInfo.MaxVertexCount = maxVertices;
		renderer = std::make_shared<Hazel::Renderer2D>(rendererInfo);

		spriteSheet = Hazel::TextureBuilder::CreateTextureFromFile(
			GetGraphicsContext(),
			"assets\\textures\\SpriteSheet.png");

		drawData.Mesh->SetColor({1.0f, 1.0f, 1.0f, 1.0f});
		drawData.Texture = spriteSheet;
		drawData.Transform.SetScale({spriteSheet->GetAspectRatio(), 1.0f});

		camera.SetAspectRatio(GetWindow().GetAspectRatio());

		particles.OnAttach(*renderer, {GetWindow(), camera}, GetInput());
	}

	void SandboxLayer::OnDetach()
	{
		particles.OnDetach();
	}

	void SandboxLayer::OnUpdate(float deltaTime)
	{
		renderTime = deltaTime;

		cameraController.UpdateCamera(camera, GetInput(), deltaTime);

		drawData.Texture.SetRegion(Hazel::Rectangle::FromBottomLeftAndSize(bottomLeft, size));

		renderer->BeginScene(camera);
		particles.OnUpdate(deltaTime);
		renderer->Render(drawData);
		renderer->EndScene();
	}

	void SandboxLayer::OnImGuiRender()
	{
		//dockspace.Begin();
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

		particles.OnImGuiRender();

		//dockspace.End();
	}

	void SandboxLayer::OnEvent(Hazel::Event &e)
	{
		cameraController.UpdateCamera(camera, e);
		e.Dispatch([this](Hazel::KeyPressEvent &e)
		{
			if (e.GetKey() == Hazel::Key::Backspace)
			{
				camera = {};
				camera.SetAspectRatio(GetWindow().GetAspectRatio());
			}
		});
	}
}