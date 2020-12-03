#include "ParticleBuilder.h"

namespace Hazel
{
	void ParticleBuilder::BuildParticle(Particle &particle, const ParticleInfo &info)
	{
		particle.Active = true;
		BuildPosition(particle, info);
		BuildVelocity(particle, info);
		BuildColor(particle, info);
		BuildLifeTime(particle, info);
		BuildSize(particle, info);
	}

	void ParticleBuilder::BuildPosition(Particle &particle, const ParticleInfo &info)
	{
		particle.Transform.Translation = glm::vec3(info.Position, 1.0f);
		particle.Transform.Rotation = glm::angleAxis(
			random.GetAngle(),
			glm::vec3(0.0f, 0.0f, 1.0f));
	}

	void ParticleBuilder::BuildVelocity(Particle &particle, const ParticleInfo &info)
	{
		particle.LinearVelocity = info.LinearVelocity + info.LinearVelocityVariation * random.GetVector2D();
	}

	void ParticleBuilder::BuildColor(Particle &particle, const ParticleInfo &info)
	{
		particle.ColorBegin = info.ColorBegin;
		particle.ColorEnd = info.ColorEnd;
	}

	void ParticleBuilder::BuildLifeTime(Particle &particle, const ParticleInfo &info)
	{
		particle.LifeTime = info.LifeTime;
		particle.RemainingLifeTime = info.LifeTime;
	}

	void ParticleBuilder::BuildSize(Particle &particle, const ParticleInfo &info)
	{
		particle.SizeBegin = info.SizeBegin + info.SizeVariation * (random.GetFloat() - 0.5f);
		particle.SizeEnd = info.SizeEnd;
	}
}