#include "ParticleRenderer.h"

#include "Hazel/Rendering/Renderer2D/SquareMesh.h"

namespace Hazel
{
	void ParticleRenderer::RenderParticle(Renderer2D &renderer, const Particle &particle)
	{
		DrawData drawData;
		drawData.Mesh = &SquareMesh::GetMesh();
		drawData.Transform = &particle.Transform;
		auto color = GetColor(particle);
		drawData.Color = &color;
		renderer.Render(drawData);
	}

	glm::vec4 ParticleRenderer::GetColor(const Particle &particle)
	{
		auto life = particle.GetLife();
		auto color = glm::mix(particle.ColorEnd, particle.ColorBegin, life);
		color.a *= life;
		return color;
	}
}