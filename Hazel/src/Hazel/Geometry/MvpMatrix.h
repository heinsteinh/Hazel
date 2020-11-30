#pragma once

#include "Transform.h"
#include "OrthographicViewport.h"

namespace Hazel
{
	class MvpMatrix
	{
	public:
		static glm::mat4 GetModel(const Transform &objectTransform)
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

		static glm::mat4 GetView(const Transform &cameraTransform)
		{
			return glm::rotate(
				glm::translate(
					glm::mat4(1.0f),
					-cameraTransform.Position),
				-cameraTransform.Angle,
				cameraTransform.Axis);
		}

		static glm::mat4 GetOrthographicProjection(const OrthographicViewport &viewport)
		{
			return glm::ortho(
				-viewport.AspectRatio * viewport.Size,
				viewport.AspectRatio * viewport.Size,
				-viewport.Size,
				viewport.Size,
				viewport.NearClip,
				viewport.FarClip);
		}

		static glm::mat4 GetViewProjection(const glm::mat4 &view, const glm::mat4 &projection)
		{
			return projection * view;
		}
	};
}