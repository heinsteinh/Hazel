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

		static constexpr Rectangle FromBottomLeftAndSize(const glm::vec2 &bottomLeft, Size size)
		{
			return {
				bottomLeft.x,
				bottomLeft.x + size.Width,
				bottomLeft.y,
				bottomLeft.y + size.Height
			};
		}

		constexpr glm::vec2 GetPosition() const
		{
			return {
				(Right + Left) / 2.0f,
				(Top + Bottom) / 2.0f
			};
		}

		constexpr float GetWidth() const
		{
			return Right - Left;
		}

		constexpr float GetHeight() const
		{
			return Top - Bottom;
		}

		constexpr Size GetSize() const
		{
			return {GetWidth(), GetHeight()};
		}

		constexpr float GetArea() const
		{
			return GetSize().GetArea();
		}

		constexpr float GetAspectRatio() const
		{
			return GetSize().GetAspectRatio();
		}

		constexpr bool IsEmpty() const
		{
			return GetWidth() == 0.0f || GetHeight() == 0.0f;
		}
	};
}