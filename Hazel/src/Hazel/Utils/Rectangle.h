#pragma once

#include "Size.h"

namespace Hazel
{
	struct Rectangle
	{
		float Left = 0.0f;
		float Right = 0.0f;
		float Bottom = 0.0f;
		float Top = 0.0f;

		static constexpr Rectangle FromAspectRatio(float aspectRatio, float zoomLevel = 1.0f)
		{
			return {
				-aspectRatio * zoomLevel,
				aspectRatio * zoomLevel,
				-zoomLevel,
				zoomLevel
			};
		}

		static constexpr Rectangle FromSizeAndCenter(Size size, const glm::vec2 &position)
		{
			return {
				position.x - size.Width,
				position.x + size.Width,
				position.y - size.Height,
				position.y + size.Height
			};
		}

		constexpr float GetX() const
		{
			return (Right + Left) / 2.0f;
		}

		constexpr float GetY() const
		{
			return (Top + Bottom) / 2.0f;
		}

		constexpr float GetWidth() const
		{
			return Right - Left;
		}

		constexpr float GetHeight() const
		{
			return Top - Bottom;
		}

		constexpr float GetArea() const
		{
			return GetWidth() * GetHeight();
		}

		constexpr bool IsEmpty() const
		{
			return GetWidth() == 0.0f || GetHeight() == 0.0f;
		}

		constexpr float GetAspectRatio() const
		{
			auto height = GetHeight();
			return height ? GetWidth() / height : 0.0f;
		}

		inline glm::mat4 ToProjectionMatrix() const
		{
			return glm::ortho(Left, Right, Bottom, Top);
		}
	};
}