#pragma once

#include "glm/glm.hpp"

#include "Hazel/Rendering/Renderer2D/Renderer2D.h"
#include "Particle.h"

namespace Hazel
{
	class ParticleRenderer
	{
	public:
		static void RenderParticle(Renderer2D &renderer, const Particle &particle)
		{
			RenderCommand command;
			command.Mesh = renderer.GetSquareMesh();
			command.Transform = particle.Transform;
			command.Color = GetColor(particle);
			command.Shader = renderer.GetDefaultShader();
			renderer.Submit(command);
		}

	private:
		static glm::vec4 GetColor(const Particle &particle)
		{
			return glm::mix(particle.ColorEnd, particle.ColorBegin, particle.GetLife());
		}
	};
}