#pragma once

#include "Particle.h"

namespace Hazel
{
	class ParticleUpdater
	{
	public:
		static inline void UpdateParticle(Particle &particle, float deltaTime)
		{
			if (particle.Active)
			{
				UpdateLifeTime(particle, deltaTime);
				if (particle.Active)
				{
					UpdatePosition(particle, deltaTime);
					UpdateSize(particle);
				}
			}
		}

	private:
		static inline void UpdateLifeTime(Particle &particle, float deltaTime)
		{
			particle.RemainingLifeTime -= deltaTime;
			if (particle.RemainingLifeTime <= 0.0f)
			{
				particle.Active = false;
			}
		}

		static inline void UpdatePosition(Particle &particle, float deltaTime)
		{
			particle.Transform.Translate(particle.LinearVelocity * deltaTime);
			particle.Transform.Angle += particle.AngularVelocity * deltaTime;
		}

		static inline void UpdateSize(Particle &particle)
		{
			particle.Transform.SetScale(particle.GetSize());
		}
	};
}