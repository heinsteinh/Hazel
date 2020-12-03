#include "CameraProjection.h"

namespace Hazel
{
	glm::vec3 CameraProjection::GetWorldPosition(const glm::vec2 &screenPosition)
	{
		return glm::unProject(
			glm::vec3(screenPosition, 0.0f),
			view,
			projection,
			glm::vec4(0.0f, windowSize.y, windowSize.x, -windowSize.y));
	}

	glm::vec2 CameraProjection::GetScreenPosition(const glm::vec3 &worldPosition)
	{
		return glm::project(
			worldPosition,
			view,
			projection,
			glm::vec4(0.0f, windowSize.y, windowSize.x, -windowSize.y));
	}
}