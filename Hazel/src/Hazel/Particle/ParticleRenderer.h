#pragma once

#include "Hazel/Rendering/Renderer2D.h"
#include "Hazel/Rendering/Batch/SquareMesh.h"
#include "Particle.h"

namespace Hazel
{
	class ParticleRenderer
	{
	private:
		Renderer2D &renderer;
		DrawData drawData;

	public:
		inline ParticleRenderer(Renderer2D &renderer)
			: renderer(renderer),
			drawData({SquareMesh::Get()})
		{
		}

		inline void Render(const Particle &particle)
		{
			if (particle.Active)
			{
				drawData.Mesh.SetColor(particle.GetColor());
				drawData.Transform = particle.GetTransform();
				renderer.Draw(drawData);
			}
		}
	};
}