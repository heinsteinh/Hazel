#pragma once

#include "Private/ParticlePool.h"
#include "Private/ParticleEmitter.h"
#include "Hazel/Core/Time/Rate.h"
#include "Hazel/Rendering/Renderer2D/Renderer2D.h"

namespace Hazel
{
	class ParticleSource
	{
	private:
		ParticleInfo info;
		bool enabled = true;
		ParticlePool pool;
		Rate rate = 5.0f;
		ParticleEmitter emitter;

	public:
		ParticleSource(size_t maxParticleCount = 1000);

		void EmitParticles(float deltaTime);
		void UpdateParticles(float deltaTime);
		void RenderParticles(Renderer2D &renderer);

		const ParticleInfo &GetParticleInfo() const
		{
			return info;
		}

		ParticleInfo &GetParticleInfo()
		{
			return info;
		}

		bool IsEnabled() const
		{
			return enabled;
		}

		void SetEnabled(bool enabled)
		{
			this->enabled = enabled;
		}

		const glm::vec3 &GetPosition() const
		{
			return emitter.GetPosition();
		}

		void SetPosition(const glm::vec3 &position)
		{
			emitter.SetPosition(position);
		}

		size_t GetMaxParticleCount() const
		{
			return pool.GetSize();
		}

		void SetMaxParticleCount(size_t maxParticleCount)
		{
			pool.Resize(maxParticleCount);
		}

		float GetEmissionRate() const
		{
			return rate;
		}

		void SetEmissionRate(float rate)
		{
			this->rate = rate;
		}
	};
}