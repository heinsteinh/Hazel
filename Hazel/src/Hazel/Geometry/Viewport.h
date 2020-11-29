#pragma once

#include "Rectangle.h"

namespace Hazel
{
	class Viewport
	{
	public:
		static constexpr Rectangle FromAspectRatio(float aspectRatio, float zoomLevel = 1.0f)
		{
			return {
				-aspectRatio * zoomLevel,
				aspectRatio * zoomLevel,
				-zoomLevel,
				zoomLevel
			};
		}

		static constexpr float GetAspectRatio(const Rectangle &viewport)
		{
			return viewport.GetAspectRatio();
		}

		static constexpr float GetZoomLevel(const Rectangle &viewport)
		{
			return viewport.GetHeight() / 2.0f;
		}
	};
}