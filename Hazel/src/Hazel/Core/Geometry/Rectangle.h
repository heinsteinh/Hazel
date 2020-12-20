#pragma once

#include "glm/glm.hpp"

#include "Size.h"

namespace Hazel
{
	struct Rectangle
	{
		float Left = 0.0f;
		float Right = 0.0f;
		float Bottom = 0.0f;
		float Top = 0.0f;

		static constexpr Rectangle FromBottomLeftAndSize(const glm::vec2 &bottomLeft, const glm::vec2 &size)
		{
			return {
				bottomLeft.x,
				bottomLeft.x + size.x,
				bottomLeft.y,
				bottomLeft.y + size.y
			};
		}

		static constexpr Rectangle FromPositionAndSize(const glm::vec2 &position, const glm::vec2 &size)
		{
			return {
				position.x - size.x / 2.0f,
				position.x + size.x / 2.0f,
				position.y - size.y / 2.0f,
				position.y + size.y / 2.0f
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

		constexpr glm::vec2 GetSize() const
		{
			return {GetWidth(), GetHeight()};
		}

		constexpr glm::vec2 GetBottomLeft() const
		{
			return {Left, Bottom};
		}

		constexpr float GetArea() const
		{
			return GetWidth() * GetHeight();
		}

		constexpr float GetAspectRatio() const
		{
			return Size::GetAspectRatio(GetSize());
		}

		constexpr bool IsEmpty() const
		{
			return GetWidth() == 0.0f || GetHeight() == 0.0f;
		}

		constexpr void Scale(float scale)
		{
			Scale(scale, scale);
		}

		constexpr void Scale(float scaleX, float scaleY)
		{
			Left *= scaleX;
			Right *= scaleX;
			Bottom *= scaleY;
			Top *= scaleY;
		}

		constexpr bool operator==(const Rectangle &other) const
		{
			return Left == other.Left && Right == other.Right && Bottom == other.Bottom && Top == other.Top;
		}

		constexpr bool operator!=(const Rectangle &other) const
		{
			return !(*this == other);
		}
	};
}