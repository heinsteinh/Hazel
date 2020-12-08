#include "SceneRenderer.h"

#include "Hazel/Components/SpriteComponent.h"
#include "Hazel/Components/ParticleSourceComponent.h"
#include "Hazel/Systems/ParticleSystem.h"
#include "Hazel/Systems/SpriteRenderingSystem.h"

namespace Hazel
{
	void SceneRenderer::RenderScene(SceneContext &context)
	{
		auto &camera = context.GetSceneCamera();
		if (camera.IsValid())
		{
			auto &renderer = context.GetRenderer();
			renderer.BeginScene(camera.GetViewProjection());
			SpriteRenderingSystem::OnRender(context);
			ParticleSystem::OnRender(context);
			renderer.EndScene();
		}
	}
}