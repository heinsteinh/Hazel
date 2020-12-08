#include "SpriteRenderingSystem.h"

#include "Private/SpriteRenderer.h"

namespace Hazel
{
	void SpriteRenderingSystem::OnRender(SceneContext &context)
	{
		context.GetRegistry().view<SpriteComponent>().each([&](auto entity, auto &component)
		{
			SpriteRenderer::RenderSprite(context, entity, component);
		});
	}
}