#pragma once

#include "Range.h"

namespace Hazel
{
	struct Bounds
	{
		glm::vec3 Min{0.0f};
		glm::vec3 Max{0.0f};

		constexpr bool ContainsX(float position) const
		{
			return Range::Contains(position, Min.x, Max.x);
		}

		constexpr bool ContainsY(float position) const
		{
			return Range::Contains(position, Min.y, Max.y);
		}

		constexpr bool ContainsZ(float position) const
		{
			return Range::Contains(position, Min.z, Max.z);
		}

		constexpr bool Contains(const glm::vec2 &position) const
		{
			return ContainsX(position.x) && ContainsY(position.y);
		}

		constexpr bool Contains(const glm::vec3 &position) const
		{
			return ContainsX(position.x) && ContainsY(position.y) && ContainsZ(position.z);
		}

		constexpr float ClampX(float position) const
		{
			return Range::Clamp(position, Min.x, Max.x);
		}

		constexpr float ClampY(float position) const
		{
			return Range::Clamp(position, Min.y, Max.y);
		}

		constexpr float ClampZ(float position) const
		{
			return Range::Clamp(position, Min.z, Max.z);
		}

		constexpr glm::vec2 Clamp(const glm::vec2 &position) const
		{
			return {ClampX(position.x), ClampY(position.y)};
		}

		constexpr glm::vec3 Clamp(const glm::vec3 &position) const
		{
			return {ClampX(position.x), ClampY(position.y), ClampZ(position.z)};
		}
	};
}