#pragma once

#include "glm/glm.hpp"

#include "Hazel/Rendering/Renderer2D/Renderer2D.h"
#include "Particle.h"

namespace Hazel
{
	class ParticleRenderer
	{
	private:
		Renderer2D *renderer;

	public:
		ParticleRenderer(Renderer2D &renderer)
			: renderer(&renderer)
		{
		}

		void RenderParticle(const Particle &particle)
		{
			auto &command = renderer->AddRenderCommand();
			command.Mesh = renderer->GetSquareMesh();
			command.Transform = particle.Transform;
			command.Color = GetColor(particle);
			command.Shader = renderer->GetDefaultShader();
		}

	private:
		glm::vec4 GetColor(const Particle &particle)
		{
			return glm::mix(particle.ColorEnd, particle.ColorBegin, particle.GetLife());
		}
	};
}