#pragma once

#include "Hazel/Core/Camera/CameraProjection.h"
#include "Hazel/Scene/Entity/Entity.h"

namespace Hazel
{
	struct CameraComponent
	{
		CameraProjection Projection;
	};

	template<>
	inline void EntityListener::OnComponentAdded(Entity entity, CameraComponent &component)
	{
		component.Projection.SetAspectRatio(entity.GetSceneContext().Camera.Viewport.GetAspectRatio());
	};
}