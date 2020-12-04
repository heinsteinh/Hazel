#include "SandboxLayer.h"

#include "imgui.h"

#include "Hazel/Textures/TextureBuilder.h"
#include "Hazel/Rendering/SquareMesh.h"

namespace Sandbox
{
	SandboxLayer::SandboxLayer()
		: Layer("Sandbox"),
		squareMesh(Hazel::SquareMesh::CreateMesh()),
		drawData{squareMesh.get(), &transform}
	{
	}

	void SandboxLayer::OnAttach()
	{
		auto &graphicsContext = GetGraphicsContext();

		Hazel::BatchInfo rendererInfo;
		rendererInfo.MaxIndexCount = maxIndices;
		rendererInfo.MaxVertexCount = maxVertices;
		rendererInfo.MaxTextureSlotCount = graphicsContext.GetMaxTextureSlotCount();
		renderer = std::make_shared<Hazel::Renderer2D>(graphicsContext, rendererInfo);

		spriteSheet = Hazel::TextureBuilder::CreateTextureFromFile(
			GetGraphicsContext(),
			"assets\\textures\\SpriteSheet.png");

		drawData.Texture = &spriteSheet;
		transform.Scale = glm::vec3(spriteSheet.GetAspectRatio(), 1.0f, 1.0f);

		particles = std::make_shared<Hazel::TestParticle>(*renderer, camera, GetInput());

		scene.SetRenderer(*renderer);

		camera = scene.CreateEntity();
		camera.AddComponent<Hazel::TransformComponent>();
		camera.AddComponent<Hazel::CameraComponent>();

		square = scene.CreateEntity();
		square.AddComponent<Hazel::TransformComponent>().Transform.Scale.x = spriteSheet.GetAspectRatio();
		square.AddComponent<Hazel::SpriteComponent>();
		square.AddComponent<Hazel::TextureComponent>(spriteSheet);
	}

	void SandboxLayer::OnDetach()
	{
	}

	void SandboxLayer::OnUpdate(float deltaTime)
	{
		renderTime = deltaTime;
		spriteSheet.SetRegion(Hazel::Rectangle::FromBottomLeftAndSize(bottomLeft, size));
		scene.OnUpdate(deltaTime);
		particles->OnUpdate(deltaTime);
	}

	void SandboxLayer::OnImGuiRender()
	{
		ImGui::Begin("Info");
		ImGui::Text("Update Time: %.2fms (%.2fFPS)", 1000 * renderTime, 1.0f / renderTime);
		ImGui::End();

		transformUI.Draw("Camera", camera.GetComponent<Hazel::TransformComponent>().Transform);
		transformUI.Draw("Transform", square.GetComponent<Hazel::TransformComponent>().Transform);

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

		particles->OnImGuiRender();
	}

	void SandboxLayer::OnEvent(Hazel::Event &e)
	{
		e.Dispatch([this](Hazel::WindowResizeEvent &e)
		{
			scene.OnViewportResize(e.GetSize());
		});
	}
}