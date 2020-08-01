#pragma once

#include "Particle.h"

namespace Hazel
{
	class ParticleUpdater
	{
	public:
		inline void Update(Particle &particle, float deltaTime)
		{
			if (particle.Active)
			{
				UpdateLifeTime(particle, deltaTime);
				if (particle.Active)
				{
					UpdatePosition(particle, deltaTime);
				}
			}
		}

	private:
		inline void UpdateLifeTime(Particle &particle, float deltaTime)
		{
			particle.RemainingLifeRime -= deltaTime;
			if (particle.RemainingLifeRime <= 0.0f)
			{
				particle.Active = false;
			}
		}

		inline void UpdatePosition(Particle &particle, float deltaTime)
		{
			particle.Position = particle.LinearVelocity * deltaTime;
			particle.Rotation += particle.AngularVelocity * deltaTime;
		}
	};
}