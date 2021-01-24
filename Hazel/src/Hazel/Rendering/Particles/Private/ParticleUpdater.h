#pragma once

#include "Particle.h"

namespace Hazel
{
	class ParticleUpdater
	{
	public:
		static void UpdateParticle(Particle &particle, float deltaTime)
		{
			UpdateLifeTime(particle, deltaTime);
			if (particle.Active)
			{
				UpdatePosition(particle, deltaTime);
				UpdateSize(particle);
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
			particle.Transform.Translation += glm::vec3(particle.LinearVelocity * deltaTime, 0.0f);
			particle.Transform.Rotation = glm::rotate(
				particle.Transform.Rotation,
				particle.AngularVelocity * deltaTime,
				glm::vec3(0.0f, 0.0f, 1.0f));
		}

		static void UpdateSize(Particle &particle)
		{
			particle.Transform.Scale = particle.GetSize() * glm::vec3(1.0f);
		}
	};
}