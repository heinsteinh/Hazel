#pragma once

#include "Hazel/Scene/Entity/SceneContext.h"
#include "Hazel/Scene/Rendering/SpriteRenderer.h"

namespace Hazel
{
	class SpriteRenderingSystem
	{
	public:
		static void OnRender(SceneContext &context)
		{
			context.Registry.view<SpriteComponent>().each([&](auto entity, auto &component)
			{
				SpriteRenderer::RenderSprite(context, entity, component);
			});
		}
	};
}