#pragma once

#include "Hazel/Scene/SceneContext.h"
#include "Hazel/Components/SpriteComponent.h"
#include "Hazel/Components/TransformComponent.h"
#include "Hazel/Components/TextureComponent.h"

namespace Hazel
{
	class SpriteRenderer
	{
	public:
		static void RenderSprite(SceneContext &context, entt::entity entity, const SpriteComponent &sprite);

	private:
		static void AddMesh(DrawData &drawData);
		static void AddTransform(DrawData &drawData, const TransformComponent *transform);
		static void AddTexture(DrawData &drawData, const TextureComponent *component);
		static void AddColor(DrawData &drawData, const SpriteComponent &sprite);
	};
}