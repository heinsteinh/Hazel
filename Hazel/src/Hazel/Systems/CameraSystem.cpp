#include "CameraSystem.h"

#include "Hazel/Components/CameraComponent.h"

namespace Hazel
{
	void CameraSystem::OnUpdate(SceneContext &context)
	{
		context.GetSceneCamera().Update();
	}

	void CameraSystem::OnViewportResize(SceneContext &context, const Rectangle &viewport)
	{
		context.GetSceneCamera().SetViewport(viewport);
		context.GetRegistry().view<CameraComponent>().each([&](auto entity, auto &component)
		{
			component.SetViewport(viewport);
		});
	}
}