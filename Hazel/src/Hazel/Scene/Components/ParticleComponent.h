#pragma once

#include "Hazel/Rendering/Particles/ParticleSource.h"

namespace Hazel
{
	struct ParticleComponent
	{
		ParticleInfo ParticleInfo;
		ParticleSource ParticleSource;

		void EmitParticle(const glm::vec3 &position)
		{
			ParticleSource.EmitParticles(position, ParticleInfo);
		}

		void UpdateParticles(const glm::vec3 &position, float deltaTime)
		{
			ParticleSource.AutoEmitParticles(position, ParticleInfo, deltaTime);
			ParticleSource.UpdateParticles(deltaTime);
		}

		void RenderParticles(Renderer2D &renderer)
		{
			ParticleSource.RenderParticles(renderer);
		}
	};
}