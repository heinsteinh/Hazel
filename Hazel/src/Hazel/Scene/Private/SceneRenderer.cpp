#include "SceneRenderer.h"

#include "Hazel/Components/SpriteComponent.h"
#include "Hazel/Components/ParticleSystemComponent.h"

namespace Hazel
{
	void SceneRenderer::OnUpdate(SceneContext &context)
	{
		if (context.MainCamera == entt::null)
		{
			return;
		}
		context.Renderer->BeginScene(context.CameraProjection.GetViewProjection());
		context.Registry.view<SpriteComponent>().each([&](auto entity, auto &component)
		{
			spriteRenderer.RenderSprite(context, entity, component);
		});
		context.Registry.view<ParticleSystemComponent>().each([&](auto entity, auto &component)
		{
			component.ParticleSystem.RenderActiveParticles(*context.Renderer);
		});
		context.Renderer->EndScene();
	}
}