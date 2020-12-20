#pragma once

#include "Hazel/Rendering/Particles/ParticleSource.h"
#include "Hazel/Rendering/Particles/DefaultParticleSettings.h"

namespace Hazel
{
	struct ParticleComponent
	{
		ParticleInfo ParticleInfo = DefaultParticleSettings::GetParticleInfo();
		ParticleSource ParticleSource{DefaultParticleSettings::GetMaxParticleCount()};

		void EmitParticle()
		{
			ParticleSource.EmitParticle(ParticleInfo);
		}

		void UpdateParticles(float deltaTime)
		{
			ParticleSource.UpdateParticles(deltaTime);
		}

		void RenderParticles(Renderer2D &renderer)
		{
			ParticleSource.RenderParticles(renderer);
		}
	};
}