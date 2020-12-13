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

		void SetViewport(const Rectangle &viewport)
		{
			Camera.SetViewport(viewport);
		}
	};

	template<>
	inline void EntityEvents::OnComponentAdded<CameraComponent>(Entity entity, CameraComponent &component)
	{
		component.SetViewport(entity.GetSceneContext().GetViewport());
	};
}