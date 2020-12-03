#pragma once

#include "Hazel/Rendering/Renderer2D.h"
#include "Hazel/Rendering/SquareMesh.h"
#include "Particle.h"

namespace Hazel
{
	class ParticleRenderer
	{
	private:
		std::shared_ptr<Mesh> squareMesh = SquareMesh::CreateMesh();

	public:
		void RenderParticle(Renderer2D &renderer, const Particle &particle);

	private:
		glm::vec4 GetColor(const Particle &particle);
	};
}