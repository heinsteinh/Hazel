#pragma once

#include "Hazel/Geometry/Rectangle.h"

namespace Hazel
{
	struct TextureCoordinates
	{
		Rectangle Coordinates;

		static constexpr TextureCoordinates FromTextureSize(Size size)
		{
			return {0.0f, size.Width, 0.0f, size.Height};
		}

		static constexpr TextureCoordinates FromBottomLeftAndSize(const glm::vec2 &bottomLeft, Size size)
		{
			return {
				bottomLeft.x,
				bottomLeft.x + size.Width,
				bottomLeft.y,
				bottomLeft.y + size.Height
			};
		}

		constexpr glm::vec2 GetBottomLeft() const
		{
			return {Coordinates.Left, Coordinates.Bottom};
		}

		constexpr Size GetSize() const
		{
			return Coordinates.GetSize();
		}
	};
}