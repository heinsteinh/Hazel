#pragma once

#include "Particle.h"

namespace Hazel
{
	class ParticleUpdater
	{
	public:
		static void UpdateParticle(Particle &particle, float deltaTime);

	private:
		static void UpdateLifeTime(Particle &particle, float deltaTime);
		static void UpdatePosition(Particle &particle, float deltaTime);
		static void UpdateSize(Particle &particle);
	};
}