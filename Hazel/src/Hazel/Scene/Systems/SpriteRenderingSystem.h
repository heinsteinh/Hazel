#pragma once

#include "Hazel/Scene/Scene/Scene.h"
#include "Private/SpriteRenderer.h"

namespace Hazel
{
	class SpriteRenderingSystem
	{
	public:
		static void OnRender(Scene &scene)
		{
			scene.ForEach<SpriteComponent>([&](auto entity, auto &component)
			{
				SpriteRenderer::RenderSprite(entity, component);
			});
		}
	};
}