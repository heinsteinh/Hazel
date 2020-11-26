#pragma once

#include "Particle.h"

namespace Hazel
{
	class ParticleUpdater
	{
	public:
		static void UpdateParticle(Particle &particle, float deltaTime)
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
		static void UpdateLifeTime(Particle &particle, float deltaTime)
		{
			particle.RemainingLifeTime -= deltaTime;
			if (particle.RemainingLifeTime <= 0.0f)
			{
				particle.Active = false;
			}
		}

		static void UpdatePosition(Particle &particle, float deltaTime)
		{
			particle.Transform.Translate(particle.LinearVelocity * deltaTime);
			particle.Transform.Angle += particle.AngularVelocity * deltaTime;
		}

		static void UpdateSize(Particle &particle)
		{
			particle.Transform.SetScale(particle.GetSize());
		}
	};
}