#pragma once

#include "Hazel/Rendering/SquareMesh.h"
#include "SceneContext.h"
#include "Hazel/Components/SpriteComponent.h"
#include "Hazel/Components/TransformComponent.h"
#include "Hazel/Components/TextureComponent.h"

namespace Hazel
{
	class SceneRenderer
	{
	private:
		std::shared_ptr<Mesh> squareMesh = SquareMesh::CreateMesh();

	public:
		void RenderSprites(SceneContext &context);

	private:
		void RenderSprite(SceneContext &context, entt::entity entity, const SpriteComponent &sprite);
		void AddMesh(DrawData &drawData);
		void AddTransform(DrawData &drawData, const TransformComponent *transform);
		void AddTexture(DrawData &drawData, const TextureComponent *component);
		void AddColor(DrawData &drawData, const SpriteComponent &sprite);
	};
}