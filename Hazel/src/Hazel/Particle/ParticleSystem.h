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

		void UpdateActiveParticles(float deltaTime);
		void RenderActiveParticles(Renderer2D &renderer);
		void EmitParticle(const ParticleInfo &info);
		size_t GetMaxParticles() const;
		void SetMaxParticles(size_t maxParticles);
	};
}