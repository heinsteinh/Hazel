#include "ParticleSystem.h"

#include "ParticleUpdater.h"

namespace Hazel
{
	ParticleSystem::ParticleSystem(size_t maxParticles)
		: pool(maxParticles > 0 ? maxParticles : 1)
	{
	}

	void ParticleSystem::UpdateParticles(float deltaTime)
	{
		for (auto &particle : pool)
		{
			ParticleUpdater::UpdateParticle(particle, deltaTime);
		}
	}

	void ParticleSystem::RenderActiveParticles(Renderer2D &renderer)
	{
		for (const auto &particle : pool)
		{
			this->renderer.RenderParticle(renderer, particle);
		}
	}

	void ParticleSystem::EmitParticle(const ParticleInfo &info)
	{
		builder.BuildParticle(pool[index], info);
		index = (index + 1) % pool.size();
	}

	size_t ParticleSystem::GetMaxParticleCount() const
	{
		return pool.size();
	}

	void ParticleSystem::SetMaxParticleCount(size_t maxParticleCount)
	{
		pool.resize(maxParticleCount > 0 ? maxParticleCount : 1);
		index %= pool.size();
	}
}