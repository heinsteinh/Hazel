#pragma once

#include "imgui.h"

#include "Hazel/ParticleSystem/ParticleInfo.h"

namespace Hazel
{
	class ParticleInfoPanel
	{
	private:
		int emissionCount = 5;
		int maxParticleCount = 1000;

	public:
		void Draw(const char *label, ParticleInfo &particleInfo)
		{
			ImGui::Begin(label);
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
			ImGui::SliderInt("EmissionCount", &emissionCount, 0, 100);
			ImGui::SliderInt("MaxParticleCount", &maxParticleCount, 1, 100000);
			ImGui::End();
		}

		int GetEmissionCount() const
		{
			return emissionCount;
		}

		int GetMaxParticleCount() const
		{
			return maxParticleCount;
		}
	};
}