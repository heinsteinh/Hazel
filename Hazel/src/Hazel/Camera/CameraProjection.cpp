#include "CameraProjection.h"

#include "Hazel/Geometry/MvpMatrix.h"

namespace Hazel
{
	glm::vec3 CameraProjection::GetWorldPosition(const glm::vec2 &screenPosition) const
	{
		return glm::unProject(
			glm::vec3(screenPosition, 0.0f),
			view,
			projection,
			glm::vec4(0.0f, viewport.y, viewport.x, -viewport.y));
	}

	glm::vec2 CameraProjection::GetScreenPosition(const glm::vec3 &worldPosition) const
	{
		return glm::project(
			worldPosition,
			view,
			projection,
			glm::vec4(0.0f, viewport.y, viewport.x, -viewport.y));
	}

	void CameraProjection::UpdateViewProjection(const glm::mat4 &view, const glm::mat4 &projection)
	{
		this->view = view;
		this->projection = projection;
		viewProjection = MvpMatrix::GetViewProjection(view, projection);
	}
}