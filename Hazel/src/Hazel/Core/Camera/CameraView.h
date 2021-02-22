#pragma once

#include "Hazel/Core/Geometry/Transform.h"
#include "Hazel/Core/Geometry/Box2D.h"

namespace Hazel
{
	class CameraView
	{
	public:
		static glm::vec4 GetProjectionViewport(const Box2D &viewport)
		{
			return glm::vec4(
				viewport.Min.x,
				viewport.Max.y,
				viewport.GetWidth(),
				-viewport.GetHeight());
		}

		static glm::mat4 GetViewMatrix(const Transform &cameraTransform)
		{
			return static_cast<glm::mat4>(glm::inverse(cameraTransform.Rotation))
				* glm::translate(glm::mat4(1.0f), -cameraTransform.Translation);
		}
	};
}