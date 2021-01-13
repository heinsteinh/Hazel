#include "ParticleRenderer.h"

#include "Hazel/Rendering/Renderer2D/SquareMesh.h"

namespace Hazel
{
	void ParticleRenderer::RenderParticle(Renderer2D &renderer, const Particle &particle)
	{
		/*RenderCommand command;
		command.Mesh = squareMesh.get();
		command.Transform = &particle.Transform;
		auto color = GetColor(particle);
		command.Material.Color = color;
		renderer.Render(drawData);*/
	}

	glm::vec4 ParticleRenderer::GetColor(const Particle &particle)
	{
		auto life = particle.GetLife();
		auto color = glm::mix(particle.ColorEnd, particle.ColorBegin, life);
		color.a *= life;
		return color;
	}
}