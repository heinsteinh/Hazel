#include "SceneRenderer.h"

#include "SceneCamera.h"

namespace Hazel
{
	void SceneRenderer::OnUpdate(SceneContext &context)
	{
		auto viewProjection = SceneCamera::GetViewProjection(context);
		if (viewProjection)
		{
			context.Renderer->BeginScene(viewProjection.value());
			context.Registry.view<SpriteComponent>().each([&](auto entity, auto &component)
			{
				spriteRenderer.RenderSprite(context, entity, component);
			});
			context.Renderer->EndScene();
		}
	}
}