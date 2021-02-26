#pragma once

#include "Hazel/Scene/Entity/Entity.h"
#include "Hazel/Scene/Components/CameraComponent.h"
#include "Private/ProjectionTypeCombo.h"
#include "Private/OrthographicProjectionInput.h"
#include "Private/PerspectiveProjectionInput.h"

namespace Hazel
{
	class CameraNode
	{
	public:
		static bool Draw(Entity entity, CameraComponent &component)
		{
			return Draw(component.Projection);
		}

		static bool Draw(CameraProjection &projection)
		{
			auto changed = ProjectionTypeCombo::Draw(projection.ProjectionType);
			switch (projection.ProjectionType)
			{
			case ProjectionType::Orthographic:
				changed |= OrthographicProjectionInput::Draw(projection.OrthographicProjection);
				break;
			case ProjectionType::Perspective:
				changed |= PerspectiveProjectionInput::Draw(projection.PerspectiveProjection);
				break;
			}
			return changed;
		}
	};
}