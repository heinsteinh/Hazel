#include "ParticleRenderer.h"

#include "Hazel/Geometry/MvpMatrix.h"

namespace Hazel
{
	void ParticleRenderer::RenderParticle(Renderer2D &renderer, const Particle &particle)
	{
		if (particle.Active)
		{
			DrawData drawData;
			squareMesh->SetColor(GetColor(particle));
			drawData.Mesh = squareMesh.get();
			auto matrix = MvpMatrix::GetModel(particle.Transform);
			drawData.Transform = &matrix;
			renderer.Render(drawData);
		}
	}

	glm::vec4 ParticleRenderer::GetColor(const Particle &particle)
	{
		auto life = particle.GetLife();
		auto color = glm::mix(particle.ColorEnd, particle.ColorBegin, life);
		color.a *= life;
		return color;
	}
}