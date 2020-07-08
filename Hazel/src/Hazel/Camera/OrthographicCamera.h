#pragma once

#include "Hazel/Geometry/Rectangle.h"

namespace Hazel
{
	struct OrthographicCamera
	{
		glm::vec2 Position = {0.0f, 0.0f};
		float Rotation = 0.0f;
		float AspectRatio = 1.0f;
		float ZoomLevel = 1.0f;

		constexpr OrthographicCamera(float aspectRatio, float zoomLevel = 1.0f)
			: AspectRatio(aspectRatio),
			ZoomLevel(zoomLevel)
		{
		}

		constexpr Rectangle GetViewport() const
		{
			return Rectangle::FromAspectRatio(AspectRatio, ZoomLevel);
		}

		inline glm::mat4 GetViewMatrix() const
		{
			return glm::translate(
				glm::rotate(
					glm::mat4(1.0f),
					-Rotation,
					{0.0f, 0.0f, 1.0f}),
				-glm::vec3(Position.x, Position.y, 0.0f));
		}

		inline glm::mat4 GetProjectionMatrix() const
		{
			auto viewport = GetViewport();
			return glm::ortho(viewport.Left, viewport.Right, viewport.Bottom, viewport.Top);
		}

		inline glm::mat4 GetViewProjectionMatrix() const
		{
			return GetProjectionMatrix() * GetViewMatrix();
		}
	};
}