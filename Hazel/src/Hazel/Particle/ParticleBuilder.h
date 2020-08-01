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
		inline void Build(Particle &particle, const ParticleInfo &info)
		{
			particle.Active = true;
			BuildPosition(particle, info);
			BuildVelocity(particle, info);
			BuildColor(particle, info);
			BuildLifeTime(particle, info);
			BuildSize(particle, info);
		}

	private:
		inline void BuildPosition(Particle &particle, const ParticleInfo &info)
		{
			particle.Position = info.Position;
			particle.Rotation = random.NextFloat() * 2 * glm::pi<float>();
		}

		inline void BuildVelocity(Particle &particle, const ParticleInfo &info)
		{
			particle.LinearVelocity = info.LinearVelocity;
			particle.LinearVelocity.x += info.LinearVelocityVariation.x * (random.NextFloat() - 0.5f);
			particle.LinearVelocity.y += info.LinearVelocityVariation.y * (random.NextFloat() - 0.5f);
		}

		inline void BuildColor(Particle &particle, const ParticleInfo &info)
		{
			particle.ColorBegin = info.ColorBegin;
			particle.ColorEnd = info.ColorEnd;
		}

		inline void BuildLifeTime(Particle &particle, const ParticleInfo &info)
		{
			particle.LifeTime = info.LifeTime;
			particle.RemainingLifeRime = info.LifeTime;
		}

		inline void BuildSize(Particle &particle, const ParticleInfo &info)
		{
			particle.SizeBegin = info.SizeBegin + info.SizeVariation * (random.NextFloat() - 0.5f);
			particle.SizeEnd = info.SizeEnd;
		}
	};
}