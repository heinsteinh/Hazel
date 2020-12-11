#include "MvpMatrix.h"

namespace Hazel
{
	glm::mat4 MvpMatrix::GetView(const Transform &cameraTransform)
	{
		return static_cast<glm::mat4>(glm::inverse(cameraTransform.Rotation))
			* glm::translate(glm::mat4(1.0f), -cameraTransform.Translation);
	}

	glm::mat4 MvpMatrix::GetViewProjection(const glm::mat4 &view, const glm::mat4 &projection)
	{
		return projection * view;
	}
}