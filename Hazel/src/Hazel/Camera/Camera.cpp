#include "Camera.h"

#define HZ_INVALID_PERSPECTIVE() HZ_ASSERT(false, "Invalid projection type")

namespace Hazel
{
	void Camera::SetViewport(const Rectangle &viewport)
	{
		auto aspectRatio = viewport.GetAspectRatio();
		orthographicProjection.AspectRatio = aspectRatio;
		perspectiveProjection.AspectRatio = aspectRatio;
		RecomputeProjection();
	}

	float Camera::GetZoomLevel() const
	{
		switch (projectionType)
		{
		case ProjectionType::Orthographic:
			return orthographicProjection.Size;
		case ProjectionType::Perspective:
			return perspectiveProjection.Fov;
		}
		HZ_INVALID_PERSPECTIVE();
	}

	void Camera::SetZoomLevel(float zoomLevel)
	{
		switch (projectionType)
		{
		case ProjectionType::Orthographic:
			orthographicProjection.Size = zoomLevel;
			break;
		case ProjectionType::Perspective:
			perspectiveProjection.Fov = zoomLevel;
			break;
		default:
			HZ_INVALID_PERSPECTIVE();
		}
		RecomputeProjection();
	}

	void Camera::RecomputeProjection()
	{
		switch (projectionType)
		{
		case ProjectionType::Orthographic:
			projection = orthographicProjection.ToMatrix();
			return;
		case ProjectionType::Perspective:
			projection = perspectiveProjection.ToMatrix();
			return;
		}
		HZ_INVALID_PERSPECTIVE();
	}
}