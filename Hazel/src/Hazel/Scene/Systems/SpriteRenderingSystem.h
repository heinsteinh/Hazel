#pragma once

#include "Hazel/Scene/Scene/SceneContext.h"
#include "Private/SpriteRenderer.h"

namespace Hazel
{
	class SpriteRenderingSystem
	{
	public:
		static void OnRender(SceneContext &context)
		{
			context.GetRegistry().view<SpriteComponent>().each([&](auto entity, auto &component)
			{
				SpriteRenderer::RenderSprite(context, entity, component);
			});
		}
	};
}