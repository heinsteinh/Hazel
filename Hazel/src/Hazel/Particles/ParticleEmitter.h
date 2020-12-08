#pragma once

#include "ParticleInfo.h"
#include "Particle.h"
#include "Hazel/Random/Random.h"

namespace Hazel
{
	class ParticleEmitter
	{
	private:
		Random random;

	public:
		void EmitParticle(Particle &particle, const ParticleInfo &info);

	private:
		void InitPosition(Particle &particle, const ParticleInfo &info);
		void InitVelocity(Particle &particle, const ParticleInfo &info);
		void InitColor(Particle &particle, const ParticleInfo &info);
		void InitLifeTime(Particle &particle, const ParticleInfo &info);
		void InitSize(Particle &particle, const ParticleInfo &info);
	};
}