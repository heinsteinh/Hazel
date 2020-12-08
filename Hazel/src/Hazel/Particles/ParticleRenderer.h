#pragma once

#include "Hazel/Rendering/Renderer2D.h"
#include "Particle.h"

namespace Hazel
{
	class ParticleRenderer
	{
	public:
		static void RenderParticle(Renderer2D &renderer, const Particle &particle);
		static glm::vec4 GetColor(const Particle &particle);
	};
}