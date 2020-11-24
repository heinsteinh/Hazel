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
		inline void BuildParticle(Particle &particle, const ParticleInfo &info)
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
			particle.Transform.SetPosition(info.Position);
			particle.Transform.Angle = random.NextFloat() * 2 * glm::pi<float>();
		}

		inline void BuildVelocity(Particle &particle, const ParticleInfo &info)
		{
			particle.LinearVelocity = info.LinearVelocity + info.LinearVelocityVariation * GetRandomDirection();
		}

		inline void BuildColor(Particle &particle, const ParticleInfo &info)
		{
			particle.ColorBegin = info.ColorBegin;
			particle.ColorEnd = info.ColorEnd;
		}

		inline void BuildLifeTime(Particle &particle, const ParticleInfo &info)
		{
			particle.LifeTime = info.LifeTime;
			particle.RemainingLifeTime = info.LifeTime;
		}

		inline void BuildSize(Particle &particle, const ParticleInfo &info)
		{
			particle.SizeBegin = info.SizeBegin + info.SizeVariation * (random.NextFloat() - 0.5f);
			particle.SizeEnd = info.SizeEnd;
		}

		inline glm::vec2 GetRandomDirection()
		{
			return {random.NextFloat() - 0.5f, random.NextFloat() - 0.5f};
		}
	};
}