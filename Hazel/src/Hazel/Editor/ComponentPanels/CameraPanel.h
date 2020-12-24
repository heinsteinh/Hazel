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
			if (Draw(component.Camera))
			{
				component.RecomputeProjection();
				return true;
			}
			return false;
		}

		bool Draw(Camera &camera)
		{
			auto result = projectionTypePanel.Draw(camera.ProjectionType);
			switch (camera.ProjectionType)
			{
			case ProjectionType::Orthographic:
				result |= orthographicProjectionPanel.Draw(camera.OrthographicProjection);
				break;
			case ProjectionType::Perspective:
				result |= perspectiveProjectionPanel.Draw(camera.PerspectiveProjection);
				break;
			}
			return result;
		}
	};
}