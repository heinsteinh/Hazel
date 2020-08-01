#include "ParticleSystem.h"

#include "Hazel/Rendering/Batch/SquareMesh.h"

namespace Hazel
{
	ParticleSystem::ParticleSystem(Renderer2D &renderer, size_t size)
		: pool(size),
		index(size > 0 ? size - 1 : 0),
		renderer(renderer),
		drawData({SquareMesh::Get()})
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
			drawData.Mesh.SetColor(particle.GetColor());
			drawData.Transform = particle.GetTransform();
			renderer.Draw(drawData);
		}
	}

	void ParticleSystem::Emit(const ParticleInfo &info)
	{
		builder.Build(pool[index], info);
		index = --index % pool.size();
	}
}