#pragma once

#include "Hazel/Scene/Scene.h"
#include "Hazel/Rendering/SquareMesh.h"

namespace Hazel
{
	class SpriteRenderSystem
	{
	private:
		static inline std::shared_ptr<Mesh> squareMesh = SquareMesh::CreateMesh();

	public:
		static void RenderSprites(Scene &scene);

	private:
		static void RenderSprite(Entity sprite, Renderer2D &renderer);
		static void AddMesh(DrawData &drawData, Entity sprite);
		static void AddTransform(DrawData &drawData, Entity sprite);
		static void AddTexture(DrawData &drawData, Entity sprite);
	};
}