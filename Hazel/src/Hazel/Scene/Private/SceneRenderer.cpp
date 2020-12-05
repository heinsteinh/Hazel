#include "SceneRenderer.h"

#include "SceneCamera.h"

namespace Hazel
{
	void SceneRenderer::OnUpdate(SceneContext &context)
	{
		auto [entity, camera] = SceneCamera::GetSceneCamera(context);
		if (camera)
		{
			context.Renderer->BeginScene(SceneCamera::GetViewProjection(context, entity, *camera));
			context.Registry.view<SpriteComponent>().each([&](auto entity, auto &component)
			{
				spriteRenderer.RenderSprite(context, entity, component);
			});
			context.Renderer->EndScene();
		}
	}
}