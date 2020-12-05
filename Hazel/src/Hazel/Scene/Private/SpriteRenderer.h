#pragma once

#include "../SceneContext.h"
#include "Hazel/Rendering/SquareMesh.h"
#include "Hazel/Components/SpriteComponent.h"
#include "Hazel/Components/TransformComponent.h"
#include "Hazel/Components/TextureComponent.h"

namespace Hazel
{
	class SpriteRenderer
	{
	private:
		std::shared_ptr<Mesh> squareMesh = SquareMesh::CreateMesh();

	public:
		void RenderSprite(SceneContext &context, entt::entity entity, const SpriteComponent &sprite);

	private:
		void AddMesh(DrawData &drawData);
		void AddTransform(DrawData &drawData, const TransformComponent *transform);
		void AddTexture(DrawData &drawData, const TextureComponent *component);
		void AddColor(DrawData &drawData, const SpriteComponent &sprite);
	};
}