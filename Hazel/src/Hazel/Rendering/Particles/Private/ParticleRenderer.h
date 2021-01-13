#pragma once

#include "glm/glm.hpp"

#include "Hazel/Rendering/Renderer2D/Renderer2D.h"
#include "Hazel/Rendering/Renderer2D/SquareMesh.h"
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