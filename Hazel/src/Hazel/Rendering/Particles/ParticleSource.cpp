#include "ParticleSource.h"

#include "Private/ParticleUpdater.h"
#include "Private/ParticleRenderer.h"

namespace Hazel
{
	ParticleSource::ParticleSource(size_t maxParticleCount)
		: pool(maxParticleCount > 0 ? maxParticleCount : 1)
	{
	}

	size_t ParticleSource::GetMaxParticleCount() const
	{
		return pool.size();
	}

	void ParticleSource::SetMaxParticleCount(size_t maxParticleCount)
	{
		pool.resize(maxParticleCount > 0 ? maxParticleCount : 1);
		index %= pool.size();
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
		for (const auto &particle : pool)
		{
			if (particle.Active)
			{
				ParticleRenderer::RenderParticle(renderer, particle);
			}
		}
	}

	void ParticleSource::EmitParticle(const ParticleInfo &info)
	{
		emitter.EmitParticle(pool[index], info);
		index = (index + 1) % pool.size();
	}
}