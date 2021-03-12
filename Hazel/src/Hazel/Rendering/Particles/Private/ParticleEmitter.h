#pragma once

#include "Hazel/Rendering/Particles/ParticleInfo.h"
#include "Particle.h"
#include "Hazel/Core/Random/Random.h"

namespace Hazel
{
	class ParticleEmitter
	{
	private:
		glm::vec3 position{0.0f};
		Random random;

	public:
		void SetupParticle(Particle &particle, const ParticleInfo &info);

		const glm::vec3 &GetPosition() const
		{
			return position;
		}

		void SetPosition(const glm::vec3 &position)
		{
			this->position = position;
		}

	private:
		void SetupPosition(Particle &particle);
		void SetupVelocity(Particle &particle, const ParticleInfo &info);
		void SetupColor(Particle &particle, const ParticleInfo &info);
		void SetupLifeTime(Particle &particle, const ParticleInfo &info);
		void SetupSize(Particle &particle, const ParticleInfo &info);
	};
}