#include "SceneManager.h"

#include "SceneCamera.h"
#include "Hazel/Components/CameraComponent.h"

namespace Hazel
{
	void SceneManager::OnUpdate(SceneContext &context, float deltaTime)
	{
		auto [entity, camera] = SceneCamera::GetSceneCamera(context);
		if (camera)
		{
			context.Renderer->BeginScene(SceneCamera::GetViewProjection(context, entity, *camera));
			renderer.RenderSprites(context);
			context.Renderer->EndScene();
		}
	}

	void SceneManager::OnViewportResize(SceneContext &context, const glm::vec2 &viewport)
	{
		auto view = context.Registry.view<CameraComponent>();
		for (auto entity : view)
		{
			view.get<CameraComponent>(entity).OnViewportResize(viewport);
		}
	}
}