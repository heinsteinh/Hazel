#pragma once

#include "Hazel/Scene/Scene/Scene.h"
#include "Private/SpriteRenderer.h"
#include "Private/EntityComparator.h"

namespace Hazel
{
	class SpriteRenderingSystem
	{
	public:
		static void OnRender(Scene &scene)
		{
			scene.Sort<SpriteComponent>([&](auto left, auto right)
			{
				return EntityComparator::CompareZCoordinates(left, right);
			});
			scene.ForEach<SpriteComponent>([](auto entity, auto &component)
			{
				SpriteRenderer::RenderSprite(entity, component);
			});
		}
	};
}