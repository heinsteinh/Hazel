#include "ParticleEmitter.h"

namespace Hazel
{
	void ParticleEmitter::EmitParticle(Particle &particle, const ParticleInfo &info)
	{
		particle.Active = true;
		InitPosition(particle, info);
		InitVelocity(particle, info);
		InitColor(particle, info);
		InitLifeTime(particle, info);
		InitSize(particle, info);
	}

	void ParticleEmitter::InitPosition(Particle &particle, const ParticleInfo &info)
	{
		particle.Transform.Translation = info.Position;
		particle.Transform.Rotation = glm::angleAxis(
			random.GetAngle(),
			glm::vec3(0.0f, 0.0f, 1.0f));
	}

	void ParticleEmitter::InitVelocity(Particle &particle, const ParticleInfo &info)
	{
		particle.LinearVelocity = info.LinearVelocity + info.LinearVelocityVariation * random.GetVector2D();
		particle.AngularVelocity = info.AngularVelocity + info.AngularVelocityVariation * random.GetFloat();
	}

	void ParticleEmitter::InitColor(Particle &particle, const ParticleInfo &info)
	{
		particle.ColorBegin = info.ColorBegin;
		particle.ColorEnd = info.ColorEnd;
	}

	void ParticleEmitter::InitLifeTime(Particle &particle, const ParticleInfo &info)
	{
		particle.LifeTime = info.LifeTime;
		particle.RemainingLifeTime = info.LifeTime;
	}

	void ParticleEmitter::InitSize(Particle &particle, const ParticleInfo &info)
	{
		particle.SizeBegin = info.SizeBegin + info.SizeVariation * (random.GetFloat() - 0.5f);
		particle.SizeEnd = info.SizeEnd;
	}
}