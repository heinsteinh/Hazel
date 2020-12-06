#include "CameraManager.h"

#include "Hazel/Components/CameraComponent.h"
#include "SceneCamera.h"

namespace Hazel
{
	void CameraManager::OnUpdate(SceneContext &context)
	{
		context.MainCamera = SceneCamera::GetSceneCamera(context);
		context.CameraProjection.UpdateViewProjection(
			SceneCamera::GetView(context, context.MainCamera),
			SceneCamera::GetProjection(context, context.MainCamera));
	}

	void CameraManager::OnViewportResize(SceneContext &context, const glm::vec2 &viewport)
	{
		context.CameraProjection.SetViewport(viewport);
		context.Registry.view<CameraComponent>().each([&](auto entity, auto &component)
		{
			component.SetViewport(viewport);
		});
	}
}