#include "ParticleUpdater.h"

namespace Hazel
{
	void ParticleUpdater::UpdateParticle(Particle &particle, float deltaTime)
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

	void ParticleUpdater::UpdateLifeTime(Particle &particle, float deltaTime)
	{
		particle.RemainingLifeTime -= deltaTime;
		if (particle.RemainingLifeTime <= 0.0f)
		{
			particle.Active = false;
		}
	}

	void ParticleUpdater::UpdatePosition(Particle &particle, float deltaTime)
	{
		particle.Transform.Translation += glm::vec3(particle.LinearVelocity * deltaTime, 0.0f);
		particle.Transform.Rotation = glm::rotate(
			particle.Transform.Rotation,
			particle.AngularVelocity * deltaTime,
			glm::vec3(0.0f, 0.0f, 1.0f));
	}

	void ParticleUpdater::UpdateSize(Particle &particle)
	{
		particle.Transform.Scale = particle.GetSize() * glm::vec3(1.0f);
	}
}