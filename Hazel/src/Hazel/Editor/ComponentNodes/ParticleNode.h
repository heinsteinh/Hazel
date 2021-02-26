#pragma once

#include "imgui.h"
#include "glm/gtc/type_ptr.hpp"

#include "Hazel/Scene/Entity/Entity.h"
#include "Hazel/Scene/Components/ParticleComponent.h"
#include "Hazel/Editor/Widgets/InputInt.h"
#include "Hazel/Editor/Widgets/InputFloat.h"
#include "Hazel/Editor/Widgets/InputColor.h"
#include "Hazel/Editor/Widgets/CheckBox.h"

namespace Hazel
{
	class ParticleNode
	{
	public:
		static bool Draw(Entity entity, ParticleComponent &component)
		{
			Draw(component.Source);
			Draw(component.Info);
			return false;
		}

	private:
		static void Draw(ParticleSource &particleSource)
		{
			auto enabled = particleSource.IsEnabled();
			if (CheckBox::Draw("Enabled", enabled))
			{
				particleSource.SetEnabled(enabled);
			}
			auto maxParticleCount = particleSource.GetMaxParticleCount();
			if (InputInt::Draw("MaxParticleCount", maxParticleCount))
			{
				particleSource.SetMaxParticleCount(maxParticleCount);
			}
			auto emissionRate = particleSource.GetEmissionRate();
			if (InputFloat::Draw("EmissionRate", emissionRate))
			{
				particleSource.SetEmissionRate(emissionRate);
			}
		}

		static void Draw(ParticleInfo &particleInfo)
		{
			InputFloat::Draw("Linear Velocity", particleInfo.LinearVelocity);
			InputFloat::Draw("Linear VelocityVariation", particleInfo.LinearVelocityVariation);
			InputFloat::Draw("Angular Velocity", particleInfo.AngularVelocity);
			InputFloat::Draw("AngularVelocityVariation", particleInfo.AngularVelocityVariation);
			InputColor::Draw("ColorBegin", particleInfo.ColorBegin);
			InputColor::Draw("ColorEnd", particleInfo.ColorEnd);
			InputFloat::Draw("SizeBegin", particleInfo.SizeBegin);
			InputFloat::Draw("SizeEnd", particleInfo.SizeEnd);
			InputFloat::Draw("SizeVariation", particleInfo.SizeVariation);
			InputFloat::Draw("LifeTime", particleInfo.LifeTime);
		}
	};
}