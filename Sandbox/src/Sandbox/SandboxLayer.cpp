#include "SandboxLayer.h"

#include "imgui.h"

#include "Hazel/Rendering/Textures/TextureBuilder.h"
#include "Hazel/Rendering/Batch/SquareMesh.h"

namespace Sandbox
{
	SandboxLayer::SandboxLayer(Hazel::Context &context)
		: renderer(context),
		settings(context.Settings),
		window(context.Window),
		input(context.Input),
		factory(context.Factory),
		camera({context.Window.GetSize().GetAspectRatio()}),
		viewport(window, camera),
		controller({context.Input, camera}),
		dispatcher(&controller),
		particleSystem(renderer),
		drawData({Hazel::SquareMesh::Get(), glm::mat4(1.0f)})
	{
		drawData.Mesh.SetColor({1.0f, 0.0f, 0.0f, 1.0f});
		defaultInfo.Position = {0.0f, 0.0f};
		defaultInfo.LinearVelocity = {0.2f, 0.2f};
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

	void SandboxLayer::OnAttach()
	{
		//texture = Hazel::TextureBuilder(factory).Build("assets\\textures\\Test.jpg");
	}

	void SandboxLayer::OnDetach()
	{
	}

	void SandboxLayer::OnUpdate(float deltaTime)
	{
		renderTime = deltaTime;

		controller.OnUpdate(deltaTime);

		if (input.IsMouseButtonPressed(Hazel::MouseButton::B1))
		{
			particleInfo.Position = viewport.GetRealPosition(input.GetMousePosition());
			for (int i = 0; i < nParticles; i++)
			{
				particleSystem.Emit(particleInfo);
			}
		}

		particleSystem.OnUpdate(deltaTime);

		renderer.BeginScene(camera);
		//renderer.Draw(drawData);
		particleSystem.OnRender();
		renderer.EndScene();
	}

	void SandboxLayer::OnImGuiRender()
	{
		ImGui::Begin("Info");
		ImGui::Text("Update Time: %f", renderTime);
		ImGui::Text("Camera Position: %f %f %f", camera.GetPosition().x, camera.GetPosition().y, camera.GetZoomLevel());
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
		ImGui::End();
	}

	void SandboxLayer::OnEvent(Hazel::Event &e)
	{
		Hazel::EventDispatcher(&controller).Dispatch(e);
	}

	void SandboxLayer::OnKeyPressed(Hazel::KeyPressEvent &e)
	{
		if (e.GetKey() == Hazel::Key::Backspace)
		{
			particleInfo = defaultInfo;
		}
	}

	void SandboxLayer::OnMouseButtonPressed(Hazel::MouseButtonPressEvent &e)
	{
	}
}