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
		return pool.GetSize();
	}

	void ParticleSource::SetMaxParticleCount(size_t maxParticleCount)
	{
		pool.Resize(maxParticleCount);
	}

	float ParticleSource::GetEmissionRate() const
	{
		return rate.GetRate();
	}

	void ParticleSource::SetEmissionRate(float rate)
	{
		this->rate.SetRate(rate);
	}

	void ParticleSource::EmitParticles(const glm::vec3 &position, const ParticleInfo &info, int count)
	{
		for (int i = 0; i < count; i++)
		{
			emitter.EmitParticle(pool.GetNextParticle(), position, info);
		}
	}

	void ParticleSource::AutoEmitParticles(const glm::vec3 &position, const ParticleInfo &info, float deltaTime)
	{
		EmitParticles(position, info, rate.GetCount(deltaTime));
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
}