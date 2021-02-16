#pragma once

#include "Hazel/Rendering/Particles/ParticleInfo.h"
#include "Particle.h"
#include "Hazel/Core/Random/Random.h"

namespace Hazel
{
	class ParticleEmitter
	{
	private:
		Random random;

	public:
		void SetupParticle(Particle &particle, const glm::vec3 &position, const ParticleInfo &info);

	private:
		void SetupPosition(Particle &particle, const glm::vec3 &position);
		void SetupVelocity(Particle &particle, const ParticleInfo &info);
		void SetupColor(Particle &particle, const ParticleInfo &info);
		void SetupLifeTime(Particle &particle, const ParticleInfo &info);
		void SetupSize(Particle &particle, const ParticleInfo &info);
	};
}