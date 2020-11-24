#include "TestParticle.h"

namespace Sandbox
{
	TestParticle::TestParticle()
		: Layer("TestParticle"),
		particleSystem(maxParticles)
	{
		defaultInfo.Position = {0.0f, 0.0f};
		defaultInfo.LinearVelocity = {0.0f, 0.0f};
		defaultInfo.LinearVelocityVariation = {0.2f, 0.2f};
		defaultInfo.AngularVelocity = {3.0f};
		defaultInfo.ColorBegin = {1.0f, 0.30f, 0.0f, 1.0f};
		defaultInfo.ColorEnd = {1.0f, 0.6f, 0.0f, 1.0f};
		defaultInfo.SizeBegin = 0.1f;
		defaultInfo.SizeEnd = 0.0f;
		defaultInfo.SizeVariation = 0.1f;
		defaultInfo.LifeTime = 2.0f;

		particleInfo = defaultInfo;
	}

	void TestParticle::OnAttach()
	{
		Hazel::RendererInfo rendererInfo;
		rendererInfo.GraphicsContext = &GetGraphicsContext();
		rendererInfo.MaxIndexCount = maxIndices;
		rendererInfo.MaxVertexCount = maxVertices;
		rendererInfo.IndexFormat = Hazel::IndexFormat::UInt16;
		renderer = std::make_shared<Hazel::Renderer2D>(rendererInfo);
		screenTransform = {GetWindow(), camera};
		camera.SetAspectRatio(GetWindow().GetAspectRatio());
	}

	void TestParticle::OnDetach()
	{
	}

	void TestParticle::OnUpdate(float deltaTime)
	{
		renderTime = deltaTime;
		auto &input = GetInput();

		controller.UpdateCamera(camera, input, deltaTime);

		if (input.IsMouseButtonPressed(Hazel::MouseButton::B1))
		{
			particleInfo.Position = screenTransform.GetWorldPosition(input.GetMousePosition());
			for (int i = 0; i < nParticles; i++)
			{
				particleSystem.EmitParticle(particleInfo);
			}
		}

		if (maxParticles != particleSystem.GetMaxParticles())
		{
			particleSystem.SetMaxParticles(maxParticles);
		}

		particleSystem.UpdateActiveParticles(deltaTime);
		renderer->BeginScene(camera);
		particleSystem.RenderActiveParticles(*renderer);
		renderer->EndScene();
	}

	void TestParticle::OnImGuiRender()
	{
		ImGui::Begin("Info");
		ImGui::Text("Update Time: %fms", 1000 * renderTime);
		ImGui::Text("Camera Position: %f %f %f", camera.GetPosition().x, camera.GetPosition().y, camera.GetZoomLevel());
		ImGui::Text("Camera Rotation: %fdeg", glm::degrees(camera.GetRotation()));
		ImGui::End();

		ImGui::Begin("ParticleInfo");
		ImGui::SliderFloat2("Position", glm::value_ptr(particleInfo.Position), -1.0f, 1.0f);
		ImGui::SliderFloat2("LinearVelocity", glm::value_ptr(particleInfo.LinearVelocity), -1.0f, 1.0f);
		ImGui::SliderFloat2("LinearVelocityVariation", glm::value_ptr(particleInfo.LinearVelocityVariation), -1.0f, 1.0f);
		ImGui::SliderFloat("AngularVelocity", &particleInfo.AngularVelocity, -3.0f, 3.0f);
		ImGui::ColorPicker4("ColorBegin", glm::value_ptr(particleInfo.ColorBegin));
		ImGui::ColorPicker4("ColorEnd", glm::value_ptr(particleInfo.ColorEnd));
		ImGui::SliderFloat("SizeBegin", &particleInfo.SizeBegin, 0.0f, 1.0f);
		ImGui::SliderFloat("SizeEnd", &particleInfo.SizeEnd, 0.0f, 1.0f);
		ImGui::SliderFloat("SizeVariation", &particleInfo.SizeVariation, 0.0f, 1.0f);
		ImGui::SliderFloat("LifeTime", &particleInfo.LifeTime, 0.0f, 10.0f);
		ImGui::SliderInt("NParticles", &nParticles, 0, 100);
		ImGui::SliderInt("MaxParticle", &maxParticles, 1, 100000);
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
	}

	inline void TestParticle::OnEvent(Hazel::Event &e)
	{
		controller.UpdateCamera(camera, e);
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