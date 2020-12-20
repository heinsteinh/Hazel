#pragma once

#include "Hazel/Core/Camera/Camera.h"
#include "Hazel/Scene/Entity/Entity.h"

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
	inline void EntityListener::OnComponentAdded<CameraComponent>(Entity entity, CameraComponent &component)
	{
		component.SetViewport(entity.GetSceneContext().Camera.GetViewport());
	};
}