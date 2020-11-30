#pragma once

#include "Transform.h"
#include "Rectangle.h"

namespace Hazel
{
	class MvpMatrix
	{
	public:
		static glm::mat4 GetModelMatrix(const Transform &objectTransform)
		{
			return glm::scale(
				glm::rotate(
					glm::translate(
						glm::mat4(1.0f),
						objectTransform.Position),
					objectTransform.Angle,
					objectTransform.Axis),
				objectTransform.Scale);
		}

		static glm::mat4 GetViewMatrix(const Transform &cameraTransform)
		{
			return glm::rotate(
				glm::translate(
					glm::mat4(1.0f),
					-cameraTransform.Position),
				-cameraTransform.Angle,
				cameraTransform.Axis);
		}

		static glm::mat4 GetOrthographicProjectionMatrix(const Rectangle &viewport)
		{
			return glm::ortho(viewport.Left, viewport.Right, viewport.Bottom, viewport.Top);
		}

		static glm::mat4 GetPerspectiveProjectionMatrix(float fov, float aspectRatio, float nearClip, float farClip)
		{
			return glm::perspective(fov, aspectRatio, nearClip, farClip);
		}

		static glm::mat4 GetViewProjectionMatrix(const glm::mat4 &view, const glm::mat4 &projection)
		{
			return projection * view;
		}
	};
}