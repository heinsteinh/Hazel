#pragma once

#include "Hazel/Scene/ComponentSystem/ComponentSystem.h"
#include "SpriteComponent.h"
#include "Private/SpriteRenderer.h"

namespace Hazel
{
	class SpriteSystem : public ComponentSystem
	{
	public:
		virtual void OnRender(Scene &scene) override
		{
			SpriteRenderer renderer(GetSceneManager().GetRenderer());
			scene.ForEach<SpriteComponent>([&](auto entity, auto &component)
			{
				renderer.RenderSprite(entity, component);
			});
		}
	};
}