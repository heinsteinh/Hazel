#pragma once

#include "Hazel/Geometry/Rectangle.h"

namespace Hazel
{
	struct OrthographicCamera
	{
		glm::vec3 Position = {0.0f, 0.0f, 0.0f};
		float Rotation = 0.0f;
		Rectangle Viewport = {-1.0f, 1.0f, -1.0f, 1.0f};

		inline float GetZoomLevel() const
		{
			return Viewport.GetHeight() / 2.0f;
		}

		inline void SetZoomLevel(float zoomLevel)
		{
			Viewport = Rectangle::FromAspectRatio(Viewport.GetAspectRatio(), zoomLevel);
		}

		constexpr void SetAspectRatio(float aspectRatio)
		{
			Viewport = Rectangle::FromAspectRatio(aspectRatio, GetZoomLevel());
		}

		inline glm::mat4 GetViewMatrix() const
		{
			return glm::translate(
				glm::rotate(
					glm::mat4(1.0f),
					-Rotation,
					{0.0f, 0.0f, 1.0f}),
				-Position);
		}

		inline glm::mat4 GetProjectionMatrix() const
		{
			return glm::ortho(Viewport.Left, Viewport.Right, Viewport.Bottom, Viewport.Top);
		}

		inline glm::mat4 GetViewProjectionMatrix() const
		{
			return GetProjectionMatrix() * GetViewMatrix();
		}
	};
}