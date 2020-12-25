#pragma once

#include "Hazel/Scene/Components/CameraComponent.h"
#include "Hazel/Editor/Widgets/ProjectionTypePanel.h"
#include "Hazel/Editor/Widgets/OrthographicProjectionPanel.h"
#include "Hazel/Editor/Widgets/PerspectiveProjectionPanel.h"

namespace Hazel
{
	class CameraPanel
	{
	private:
		ProjectionTypePanel projectionTypePanel;
		OrthographicProjectionPanel orthographicProjectionPanel;
		PerspectiveProjectionPanel perspectiveProjectionPanel;

	public:
		bool Draw(CameraComponent &component)
		{
			return Draw(component.Projection);
		}

		bool Draw(CameraProjection &projection)
		{
			auto result = projectionTypePanel.Draw(projection.ProjectionType);
			switch (projection.ProjectionType)
			{
			case ProjectionType::Orthographic:
				result |= orthographicProjectionPanel.Draw(projection.OrthographicProjection);
				break;
			case ProjectionType::Perspective:
				result |= perspectiveProjectionPanel.Draw(projection.PerspectiveProjection);
				break;
			}
			return result;
		}
	};
}