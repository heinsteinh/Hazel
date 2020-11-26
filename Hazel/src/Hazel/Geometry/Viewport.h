#pragma once

#include "Rectangle.h"

namespace Hazel
{
	struct Viewport
	{
		float AspectRatio = 1.0f;
		float ZoomLevel = 1.0f;

		glm::mat4 ToProjectionMatrix() const
		{
			auto viewport = ToRectangle();
			return glm::ortho(viewport.Left, viewport.Right, viewport.Bottom, viewport.Top);
		}

		constexpr Rectangle ToRectangle() const
		{
			return {
				-AspectRatio * ZoomLevel,
				AspectRatio * ZoomLevel,
				-ZoomLevel,
				ZoomLevel
			};
		}
	};
}