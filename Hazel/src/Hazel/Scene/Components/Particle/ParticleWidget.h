#pragma once

#include "imgui.h"
#include "glm/gtc/type_ptr.hpp"

#include "Hazel/Rendering/Particles/ParticleSource.h"
#include "Hazel/Rendering/Particles/ParticleInfo.h"
#include "Hazel/Scene/Scene/Entity.h"
#include "Hazel/Editor/Widgets/InputInt.h"
#include "Hazel/Editor/Widgets/InputFloat.h"
#include "Hazel/Editor/Widgets/InputColor.h"
#include "Hazel/Editor/Widgets/CheckBox.h"

namespace Hazel
{
	class ParticleWidget
	{
	public:
		static bool Draw(ParticleSource &particleSource)
		{
			bool changed = false;
			auto enabled = particleSource.IsEnabled();
			if (CheckBox::Draw("Enabled", enabled))
			{
				particleSource.SetEnabled(enabled);
				changed = true;
			}
			auto maxParticleCount = particleSource.GetMaxParticleCount();
			if (InputInt::Draw("MaxParticleCount", maxParticleCount))
			{
				particleSource.SetMaxParticleCount(maxParticleCount);
				changed = true;
			}
			auto emissionRate = particleSource.GetEmissionRate();
			if (InputFloat::Draw("EmissionRate", emissionRate))
			{
				particleSource.SetEmissionRate(emissionRate);
				changed = true;
			}
			changed |= Draw(particleSource.GetParticleInfo());
			return changed;
		}

	private:
		static bool Draw(ParticleInfo &particleInfo)
		{
			bool changed = false;
			changed |= InputFloat::Draw("Linear Velocity", particleInfo.LinearVelocity);
			changed |= InputFloat::Draw("Linear VelocityVariation", particleInfo.LinearVelocityVariation);
			changed |= InputFloat::Draw("Angular Velocity", particleInfo.AngularVelocity);
			changed |= InputFloat::Draw("AngularVelocityVariation", particleInfo.AngularVelocityVariation);
			changed |= InputColor::Draw("ColorBegin", particleInfo.ColorBegin);
			changed |= InputColor::Draw("ColorEnd", particleInfo.ColorEnd);
			changed |= InputFloat::Draw("SizeBegin", particleInfo.SizeBegin);
			changed |= InputFloat::Draw("SizeEnd", particleInfo.SizeEnd);
			changed |= InputFloat::Draw("SizeVariation", particleInfo.SizeVariation);
			changed |= InputFloat::Draw("LifeTime", particleInfo.LifeTime);
			return changed;
		}
	};
}