#pragma once

#include "Hazel/Scene/Context/SceneContext.h"
#include "Hazel/Scene/Components/SpriteComponent.h"
#include "Hazel/Scene/Components/TransformComponent.h"

namespace Hazel
{
	class SpriteRenderer
	{
	public:
		static void RenderSprite(SceneContext &context, entt::entity entity, const SpriteComponent &sprite);

	private:
		static void AddMesh(DrawData &drawData);
		static void AddSprite(DrawData &drawData, const SpriteComponent &sprite);
		static void AddTransform(DrawData &drawData, const TransformComponent *transform);
	};
}