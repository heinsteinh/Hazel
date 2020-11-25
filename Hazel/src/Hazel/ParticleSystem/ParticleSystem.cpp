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

	void ParticleSystem::RenderParticles(Renderer2D &renderer)
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

	size_t ParticleSystem::GetMaxParticles() const
	{
		return pool.size();
	}

	void ParticleSystem::SetMaxParticles(size_t size)
	{
		pool.resize(size > 0 ? size : 1);
		index %= pool.size();
	}
}