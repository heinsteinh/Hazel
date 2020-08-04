#pragma once

#include "Rectangle.h"

namespace Hazel
{
	struct Viewport
	{
		float AspectRatio = 1.0f;
		float ZoomLevel = 1.0f;

		inline glm::mat4 ToMatrix() const
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