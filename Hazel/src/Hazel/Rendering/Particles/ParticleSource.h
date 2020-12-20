#pragma once

#include "Private/ParticleEmitter.h"
#include "Hazel/Rendering/Renderer2D/Renderer2D.h"

namespace Hazel
{
	class ParticleSource
	{
	private:
		std::vector<Particle> pool;
		size_t index = 0;
		ParticleEmitter emitter;

	public:
		ParticleSource(size_t maxParticleCount = 1000);

		size_t GetMaxParticleCount() const;
		void SetMaxParticleCount(size_t maxParticleCount);
		void EmitParticle(const ParticleInfo &info);
		void UpdateParticles(float deltaTime);
		void RenderParticles(Renderer2D &renderer);
	};
}