#include "SceneRenderer.h"

#include "Hazel/Scene/Components/SpriteComponent.h"
#include "Hazel/Scene/Components/ParticleComponent.h"
#include "Hazel/Scene/Systems/ParticleSystem.h"
#include "Hazel/Scene/Systems/SpriteRenderingSystem.h"
#include "Hazel/Core/Exceptions/AssertionException.h"

namespace Hazel
{
	void SceneRenderer::RenderScene(SceneContext &context)
	{
		HZ_ASSERT(context.Renderer, "No renderer attached to the scene");
		if (context.PrimaryCamera != entt::null)
		{
			context.Renderer->BeginScene(context.Camera.ViewProjection);
			SpriteRenderingSystem::OnRender(context);
			ParticleSystem::OnRender(context);
			context.Renderer->EndScene();
		}
	}
}