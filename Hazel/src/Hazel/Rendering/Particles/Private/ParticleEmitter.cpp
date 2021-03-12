#include "ParticleEmitter.h"

namespace Hazel
{
	void ParticleEmitter::SetupParticle(Particle &particle, const ParticleInfo &info)
	{
		particle.Active = true;
		SetupPosition(particle);
		SetupVelocity(particle, info);
		SetupColor(particle, info);
		SetupLifeTime(particle, info);
		SetupSize(particle, info);
	}

	void ParticleEmitter::SetupPosition(Particle &particle)
	{
		particle.Transform.Translation = position;
		particle.Transform.Rotation = glm::angleAxis(
			random.GetAngle(),
			glm::vec3(0.0f, 0.0f, 1.0f));
	}

	void ParticleEmitter::SetupVelocity(Particle &particle, const ParticleInfo &info)
	{
		particle.LinearVelocity = info.LinearVelocity + info.LinearVelocityVariation * random.GetVector2D();
		particle.AngularVelocity = info.AngularVelocity + info.AngularVelocityVariation * random.GetFloat();
	}

	void ParticleEmitter::SetupColor(Particle &particle, const ParticleInfo &info)
	{
		particle.ColorBegin = info.ColorBegin;
		particle.ColorEnd = info.ColorEnd;
	}

	void ParticleEmitter::SetupLifeTime(Particle &particle, const ParticleInfo &info)
	{
		particle.LifeTime = info.LifeTime;
		particle.RemainingLifeTime = info.LifeTime;
	}

	void ParticleEmitter::SetupSize(Particle &particle, const ParticleInfo &info)
	{
		particle.SizeBegin = info.SizeBegin + info.SizeVariation * (random.GetFloat() - 0.5f);
		particle.SizeEnd = info.SizeEnd;
	}
}