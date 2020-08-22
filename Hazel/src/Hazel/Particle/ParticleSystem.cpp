#include "ParticleSystem.h"

namespace Hazel
{
	ParticleSystem::ParticleSystem(Renderer2D &renderer, size_t size)
		: pool(size > 0 ? size : 1),
		renderer(renderer)
	{
	}

	void ParticleSystem::OnUpdate(float deltaTime)
	{
		for (auto &particle : pool)
		{
			updater.Update(particle, deltaTime);
		}
	}

	void ParticleSystem::OnRender()
	{
		for (const auto &particle : pool)
		{
			renderer.Render(particle);
		}
	}

	void ParticleSystem::Emit(const ParticleInfo &info)
	{
		builder.Build(pool[index], info);
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