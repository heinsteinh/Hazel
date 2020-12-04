#pragma once

#include "Hazel/Rendering/SquareMesh.h"

namespace Hazel
{
	class Scene;
	class Entity;
	struct DrawData;
	class Renderer2D;

	class SpriteRenderer
	{
	private:
		std::shared_ptr<Mesh> squareMesh = SquareMesh::CreateMesh();

	public:
		void RenderSprites(Scene &scene);

	private:
		void RenderSprite(Entity sprite, Renderer2D &renderer);
		void AddMesh(DrawData &drawData, Entity sprite);
		void AddTransform(DrawData &drawData, Entity sprite);
		void AddTexture(DrawData &drawData, Entity sprite);
	};
}