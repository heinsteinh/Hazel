#pragma once

#include "ParticleBuilder.h"
#include "ParticleRenderer.h"
#include "Hazel/Rendering/Renderer2D.h"

namespace Hazel
{
	class ParticleSystem
	{
	private:
		std::vector<Particle> pool;
		size_t index = 0;
		ParticleBuilder builder;
		ParticleRenderer renderer;

	public:
		ParticleSystem(size_t maxParticles = 1000);

		void EmitParticle(const ParticleInfo &info);
		void UpdateParticles(float deltaTime);
		void RenderActiveParticles(Renderer2D &renderer);
		size_t GetMaxParticleCount() const;
		void SetMaxParticleCount(size_t maxParticleCount);
	};
}