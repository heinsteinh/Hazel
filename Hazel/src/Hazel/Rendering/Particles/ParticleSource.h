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
		bool enabled = true;
		ParticlePool pool;
		Rate rate = 5.0f;
		ParticleEmitter emitter;

	public:
		ParticleSource(size_t maxParticleCount = 1000);

		bool IsEnabled() const;
		void SetEnabled(bool enabled);
		size_t GetMaxParticleCount() const;
		void SetMaxParticleCount(size_t maxParticleCount);
		float GetEmissionRate() const;
		void SetEmissionRate(float rate);
		void EmitParticles(const glm::vec3 &position, const ParticleInfo &info, int count = 1);
		void AutoEmitParticles(const glm::vec3 &position, const ParticleInfo &info, float deltaTime);
		void UpdateParticles(float deltaTime);
		void RenderParticles(Renderer2D &renderer);
	};
}