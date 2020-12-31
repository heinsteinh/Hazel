#pragma once

#include "Hazel/Scene/Scene/Scene.h"
#include "Private/SpriteRenderer.h"

namespace Hazel
{
	class SpriteRenderingSystem
	{
	public:
		static void OnRender(Scene &scene, Renderer2D &renderer)
		{
			scene.ForEach<SpriteComponent>([&](auto entity, auto &component)
			{
				SpriteRenderer::RenderSprite(renderer, entity, component);
			});
		}
	};
}