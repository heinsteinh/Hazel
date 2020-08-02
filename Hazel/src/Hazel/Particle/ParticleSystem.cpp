#include "ParticleSystem.h"

namespace Hazel
{
	ParticleSystem::ParticleSystem(Renderer2D &renderer, size_t size)
		: pool(size == 0 ? 1 : size),
		index(size > 0 ? size - 1 : 0),
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
		index = --index % pool.size();
	}
}