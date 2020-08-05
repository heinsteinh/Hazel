#pragma once

#include "ParticleBuilder.h"
#include "ParticleUpdater.h"
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
		ParticleUpdater updater;
		ParticleRenderer renderer;

	public:
		ParticleSystem(Renderer2D &renderer, size_t size = 1000);

		void OnUpdate(float deltaTime);
		void OnRender();
		void Emit(const ParticleInfo &info);
		size_t GetMaxParticles() const;
		void SetMaxParticles(size_t size);
	};
}