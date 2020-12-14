#pragma once

#include "imgui.h"

#include "Hazel/Particles/ParticleInfo.h"

#include "Editor/Widgets/FloatInput.h"

namespace Hazel
{
	class ParticlePanel
	{
	private:
		FloatInput input;
		int emissionCount = 5;
		int maxParticleCount = 1000;

	public:
		void Draw(const char *label, ParticleInfo &particleInfo)
		{
			ImGui::Begin(label);
			input.Draw("Position", particleInfo.Position);
			input.Draw("Linear Velocity", particleInfo.LinearVelocity);
			input.Draw("Linear VelocityVariation", particleInfo.LinearVelocityVariation);
			input.Draw("Angular Velocity", particleInfo.AngularVelocity);
			input.Draw("AngularVelocityVariation", particleInfo.AngularVelocityVariation);
			ImGui::ColorEdit4("ColorBegin", glm::value_ptr(particleInfo.ColorBegin));
			ImGui::ColorEdit4("ColorEnd", glm::value_ptr(particleInfo.ColorEnd));
			input.Draw("SizeBegin", particleInfo.SizeBegin);
			input.Draw("SizeEnd", particleInfo.SizeEnd);
			input.Draw("SizeVariation", particleInfo.SizeVariation);
			input.Draw("LifeTime", particleInfo.LifeTime);
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