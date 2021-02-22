#pragma once

#include "glm/glm.hpp"

#include "Size.h"
#include "Range.h"

namespace Hazel
{
	struct Box2D
	{
		glm::vec2 Min{0.0f};
		glm::vec2 Max{0.0f};

		static constexpr Box2D FromPositionAndSize(const glm::vec2 &position, const glm::vec2 &size)
		{
			auto halfSize = size / 2.0f;
			return {position - halfSize, position + halfSize};
		}

		constexpr glm::vec2 GetPosition() const
		{
			return Min + GetSize() / 2.0f;
		}

		constexpr float GetWidth() const
		{
			return Max.x - Min.x;
		}

		constexpr float GetHeight() const
		{
			return Max.y - Min.y;
		}

		constexpr glm::vec2 GetSize() const
		{
			return Max - Min;
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
			return Min == Max;
		}

		constexpr bool ContainsX(float position) const
		{
			return Range::Contains(position, Min.x, Max.x);
		}

		constexpr bool ContainsY(float position) const
		{
			return Range::Contains(position, Min.x, Max.x);
		}

		constexpr bool Contains(const glm::vec2 &position) const
		{
			return ContainsX(position.x) && ContainsY(position.y);
		}

		constexpr float ClampX(float position) const
		{
			return Range::Clamp(position, Min.x, Max.x);
		}

		constexpr float ClampY(float position) const
		{
			return Range::Clamp(position, Min.y, Max.y);
		}

		constexpr glm::vec2 Clamp(const glm::vec2 &position) const
		{
			return {ClampX(position.x), ClampY(position.y)};
		}

		constexpr bool operator==(const Box2D &other) const
		{
			return Min == other.Min && Max == other.Max;
		}

		constexpr bool operator!=(const Box2D &other) const
		{
			return !(*this == other);
		}
	};
}