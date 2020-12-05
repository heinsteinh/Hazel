#pragma once

#include "Hazel/Camera/Camera.h"
#include "Hazel/Scene/Entity.h"

namespace Hazel
{
	struct CameraComponent
	{
		Camera Camera;

		const glm::mat4 &GetProjection()
		{
			return Camera.GetProjection();
		}

		void OnViewportResize(const glm::vec2 &viewport)
		{
			Camera.SetViewport(viewport);
		}
	};

	template<>
	inline void EntityEvents::OnAddComponent<CameraComponent>(Entity entity, CameraComponent &component)
	{
		component.OnViewportResize(entity.GetSceneContext().Viewport);
	};
}