#pragma once

#include "ParticleInfo.h"
#include "Particle.h"
#include "Hazel/Random/Random.h"

namespace Hazel
{
	class ParticleBuilder
	{
	private:
		Random random;

	public:
		void BuildParticle(Particle &particle, const ParticleInfo &info);

	private:
		void BuildPosition(Particle &particle, const ParticleInfo &info);
		void BuildVelocity(Particle &particle, const ParticleInfo &info);
		void BuildColor(Particle &particle, const ParticleInfo &info);
		void BuildLifeTime(Particle &particle, const ParticleInfo &info);
		void BuildSize(Particle &particle, const ParticleInfo &info);
	};
}