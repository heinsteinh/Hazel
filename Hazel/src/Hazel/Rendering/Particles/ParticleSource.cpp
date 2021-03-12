#include "ParticleSource.h"

#include "Private/ParticleUpdater.h"
#include "Private/ParticleRenderer.h"

namespace Hazel
{
	ParticleSource::ParticleSource(size_t maxParticleCount)
		: pool(maxParticleCount > 0 ? maxParticleCount : 1)
	{
	}

	void ParticleSource::EmitParticles(float deltaTime)
	{
		if (!enabled)
		{
			return;
		}
		auto count = rate.GetCount(deltaTime);
		for (int i = 0; i < count; ++i)
		{
			emitter.SetupParticle(pool.AddParticle(), info);
		}
	}

	void ParticleSource::UpdateParticles(float deltaTime)
	{
		for (auto &particle : pool)
		{
			if (particle.Active)
			{
				ParticleUpdater::UpdateParticle(particle, deltaTime);
			}
		}
	}

	void ParticleSource::RenderParticles(Renderer2D &renderer)
	{
		ParticleRenderer particleRenderer(renderer);
		for (const auto &particle : pool)
		{
			if (particle.Active)
			{
				particleRenderer.RenderParticle(particle);
			}
		}
	}
}