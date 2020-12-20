#include "SceneRenderer.h"

#include "Hazel/Scene/Components/SpriteComponent.h"
#include "Hazel/Scene/Components/ParticleComponent.h"
#include "Hazel/Scene/Systems/ParticleSystem.h"
#include "Hazel/Scene/Systems/SpriteRenderingSystem.h"

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