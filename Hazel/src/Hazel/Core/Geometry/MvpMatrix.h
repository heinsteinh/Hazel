#pragma once

#include "Transform.h"

namespace Hazel
{
	class MvpMatrix
	{
	public:
		static glm::mat4 GetView(const Transform &cameraTransform)
		{
			return static_cast<glm::mat4>(glm::inverse(cameraTransform.Rotation))
				* glm::translate(glm::mat4(1.0f), -cameraTransform.Translation);
		}

		static glm::mat4 GetViewProjection(const glm::mat4 &view, const glm::mat4 &projection)
		{
			return projection * view;
		}
	};
}