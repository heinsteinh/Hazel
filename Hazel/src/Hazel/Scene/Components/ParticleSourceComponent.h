#pragma once

#include "Hazel/Rendering/Particles/ParticleSource.h"

namespace Hazel
{
	struct ParticleSourceComponent
	{
		ParticleSource ParticleSource;

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