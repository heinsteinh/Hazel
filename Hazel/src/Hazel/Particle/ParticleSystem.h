#pragma once

#include "ParticleBuilder.h"
#include "ParticleUpdater.h"
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
		Renderer2D &renderer;
		DrawData drawData;

	public:
		ParticleSystem(Renderer2D &renderer, size_t size = 1000);

		void OnUpdate(float deltaTime);
		void OnRender();
		void Emit(const ParticleInfo &info);
	};
}