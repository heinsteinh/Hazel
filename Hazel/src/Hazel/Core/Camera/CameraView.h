#pragma once

#include "Hazel/Core/Geometry/Transform.h"
#include "Hazel/Core/Geometry/Rectangle.h"

namespace Hazel
{
	class CameraView
	{
	public:
		static glm::mat4 GetViewMatrix(const Transform &cameraTransform)
		{
			return static_cast<glm::mat4>(glm::inverse(cameraTransform.Rotation))
				* glm::translate(glm::mat4(1.0f), -cameraTransform.Translation);
		}

		static glm::mat4 GetViewProjectionMatrix(const glm::mat4 &view, const glm::mat4 &projection)
		{
			return projection * view;
		}

		static glm::vec4 GetProjectionViewport(const Rectangle &viewport)
		{
			return glm::vec4(
				viewport.Left,
				viewport.Top,
				viewport.GetWidth(),
				-viewport.GetHeight());
		}
	};
}