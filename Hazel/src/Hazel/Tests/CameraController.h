#pragma once

#include "Hazel/Core/Camera/CameraProjection.h"
#include "Hazel/Core/Input/Input.h"
#include "Hazel/Core/Geometry/Range.h"
#include "CameraControllerSettings.h"

namespace Hazel
{
	class CameraController
	{
	private:
		CameraControllerSettings settings;

	public:
		CameraControllerSettings &GetSettings()
		{
			return settings;
		}

		void UpdateProjection(CameraProjection &projection, const Input &input, float deltaTime)
		{
			SetZoomLevel(projection, ComputeZoomLevel(input, deltaTime, GetZoomLevel(projection)));
		}

	private:
		float ComputeZoomLevel(const Input &input, float deltaTime, float zoomLevel)
		{
			return Range::Clamp(
				zoomLevel - settings.ZoomSpeed * input.GetMouseScrollOffset().y,
				settings.MinZoomLevel,
				settings.MaxZoomLevel);
		}

		float CameraController::GetZoomLevel(const CameraProjection &projection)
		{
			switch (projection.ProjectionType)
			{
			case ProjectionType::Orthographic:
				return projection.OrthographicProjection.Size;
			case ProjectionType::Perspective:
				return projection.PerspectiveProjection.VerticalFov;
			}
			return 0.0f;
		}

		void CameraController::SetZoomLevel(CameraProjection &projection, float zoomLevel)
		{
			switch (projection.ProjectionType)
			{
			case ProjectionType::Orthographic:
				projection.OrthographicProjection.Size = zoomLevel;
				break;
			case ProjectionType::Perspective:
				projection.PerspectiveProjection.VerticalFov = zoomLevel;
				break;
			}
		}
	};
}