#pragma once

#include <vector>

#include "Particle.h"

namespace Hazel
{
	class ParticlePool
	{
	private:
		size_t index = 0;
		std::vector<Particle> particles;

	public:
		ParticlePool(size_t size)
			: particles(size)
		{
		}

		auto begin() const
		{
			return particles.begin();
		}

		auto begin()
		{
			return particles.begin();
		}

		auto end() const
		{
			return particles.end();
		}

		size_t GetSize() const
		{
			return particles.size();
		}

		void Resize(size_t size)
		{
			particles.resize(size > 0 ? size : 1);
			index %= particles.size();
		}

		Particle &GetNextParticle()
		{
			auto &particle = particles[index];
			index = (index + 1) % particles.size();
			return particle;
		}
	};
}