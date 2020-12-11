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
			return perspectiveProjection.VerticalFov;
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
			perspectiveProjection.VerticalFov = zoomLevel;
			break;
		default:
			HZ_INVALID_PERSPECTIVE();
		}
		RecomputeProjection();
	}

	void Camera::SetProjectionType(ProjectionType projectionType)
	{
		this->projectionType = projectionType;
		RecomputeProjection();
	}

	void Camera::SetOrthographicProjection(const OrthographicProjection &orthographicProjection)
	{
		this->orthographicProjection = orthographicProjection;
		if (projectionType == ProjectionType::Orthographic)
		{
			RecomputeProjection();
		}
	}

	void Camera::SetPerspectiveProjection(const PerspectiveProjection &perspectiveProjection)
	{
		this->perspectiveProjection = perspectiveProjection;
		if (projectionType == ProjectionType::Perspective)
		{
			RecomputeProjection();
		}
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