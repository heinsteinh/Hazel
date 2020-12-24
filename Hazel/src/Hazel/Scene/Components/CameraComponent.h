#pragma once

#include "Hazel/Core/Camera/Camera.h"
#include "Hazel/Scene/Entity/Entity.h"

namespace Hazel
{
	struct CameraComponent
	{
		Camera Camera;
		glm::mat4 Projection{1.0f};

		void SetViewport(const Rectangle &viewport)
		{
			Camera.SetAspectRatio(viewport.GetAspectRatio());
		}

		void RecomputeProjection()
		{
			Projection = Camera.GetProjection();
		}
	};

	template<>
	inline void EntityListener::OnComponentAdded(Entity entity, CameraComponent &component)
	{
		component.SetViewport(entity.GetSceneContext().Camera.GetViewport());
		component.RecomputeProjection();
	};
}