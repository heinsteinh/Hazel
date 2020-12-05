#include "CameraManager.h"

#include "Hazel/Components/CameraComponent.h"

namespace Hazel
{
	void CameraManager::OnViewportResize(SceneContext &context, const glm::vec2 &viewport)
	{
		context.Registry.view<CameraComponent>().each([&](auto entity, auto &component)
		{
			component.SetViewport(viewport);
		});
	}
}