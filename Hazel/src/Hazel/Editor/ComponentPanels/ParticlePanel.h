#pragma once

#include "imgui.h"
#include "glm/gtc/type_ptr.hpp"

#include "Hazel/Scene/Components/ParticleComponent.h"
#include "Hazel/Editor/Widgets/FloatInput.h"

namespace Hazel
{
	class ParticlePanel
	{
	private:
		FloatInput input;

	public:
		void Draw(ParticleComponent &component)
		{
			Draw(component.ParticleInfo);
			Draw(component.ParticleSource);
		}

		void Draw(ParticleInfo &particleInfo)
		{
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
		}

		void Draw(ParticleSource &particleSource)
		{
			auto maxParticleCount = static_cast<int>(particleSource.GetMaxParticleCount());
			if (ImGui::DragInt("MaxParticleCount", &maxParticleCount))
			{
				particleSource.SetMaxParticleCount(maxParticleCount);
			}
		}
	};
}