#include "TestParticle.h"

#include "Hazel/Geometry/ScreenTransform.h"

namespace Sandbox
{
	TestParticle::TestParticle()
		: particleSystem(maxParticles)
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

	void TestParticle::OnAttach(Hazel::Renderer2D &renderer, const Hazel::OrthographicCamera &camera, const Hazel::Input &input)
	{
		this->renderer = &renderer;
		this->camera = &camera;
		this->input = &input;
	}

	void TestParticle::OnDetach()
	{
	}

	void TestParticle::OnUpdate(float deltaTime)
	{
		if (input->IsMouseButtonPressed(Hazel::MouseButton::B1))
		{
			particleInfo.Position = Hazel::ScreenTransform::GetWorldPosition(*camera, input->GetMousePosition());
			for (int i = 0; i < nParticles; i++)
			{
				particleSystem.EmitParticle(particleInfo);
			}
		}

		if (maxParticles != particleSystem.GetMaxParticles())
		{
			particleSystem.SetMaxParticles(maxParticles);
		}

		particleSystem.UpdateParticles(deltaTime);
		particleSystem.RenderParticles(*renderer);
	}

	void TestParticle::OnImGuiRender()
	{
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
	}
}