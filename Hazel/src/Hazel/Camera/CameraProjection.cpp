#include "CameraProjection.h"

#include "Hazel/Geometry/MvpMatrix.h"

namespace Hazel
{
	glm::vec3 CameraProjection::GetWorldPosition(const CameraInfo &camera, const glm::vec2 &screenPosition)
	{
		return glm::unProject(
			glm::vec3(screenPosition, 0.0f),
			camera.View,
			camera.Projection,
			GetViewport(camera.Viewport));
	}

	glm::vec2 CameraProjection::GetScreenPosition(const CameraInfo &camera, const glm::vec3 &worldPosition)
	{
		return glm::project(
			worldPosition,
			camera.View,
			camera.Projection,
			GetViewport(camera.Viewport));
	}

	glm::vec4 CameraProjection::GetViewport(const Rectangle &viewport)
	{
		return glm::vec4(
			viewport.Left,
			viewport.Bottom + viewport.Top,
			viewport.Right,
			viewport.Bottom - viewport.Top);
	}
}