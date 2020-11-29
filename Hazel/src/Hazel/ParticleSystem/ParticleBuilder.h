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
		void BuildParticle(Particle &particle, const ParticleInfo &info)
		{
			particle.Active = true;
			BuildPosition(particle, info);
			BuildVelocity(particle, info);
			BuildColor(particle, info);
			BuildLifeTime(particle, info);
			BuildSize(particle, info);
		}

	private:
		void BuildPosition(Particle &particle, const ParticleInfo &info)
		{
			particle.Transform.SetPosition(info.Position);
			particle.Transform.Angle = random.GetFloat() * 2 * glm::pi<float>();
		}

		void BuildVelocity(Particle &particle, const ParticleInfo &info)
		{
			particle.LinearVelocity = info.LinearVelocity + info.LinearVelocityVariation * random.GetVector2D();
		}

		void BuildColor(Particle &particle, const ParticleInfo &info)
		{
			particle.ColorBegin = info.ColorBegin;
			particle.ColorEnd = info.ColorEnd;
		}

		void BuildLifeTime(Particle &particle, const ParticleInfo &info)
		{
			particle.LifeTime = info.LifeTime;
			particle.RemainingLifeTime = info.LifeTime;
		}

		void BuildSize(Particle &particle, const ParticleInfo &info)
		{
			particle.SizeBegin = info.SizeBegin + info.SizeVariation * (random.GetFloat() - 0.5f);
			particle.SizeEnd = info.SizeEnd;
		}
	};
}