#pragma once

namespace Hazel
{
	struct Boundary
	{
		glm::vec3 MinValue = {-1.0f, -1.0f, -1.0f};
		glm::vec3 MaxValue = {1.0f, 1.0f, 1.0f};

		constexpr glm::vec3 Clamp(const glm::vec3 &position) const
		{
			return glm::clamp(position, MinValue, MaxValue);
		}

		constexpr bool Contains(const glm::vec3 &position) const
		{
			return position.x <= MaxValue.x && position.x >= MinValue.x
				&& position.y <= MaxValue.y && position.y >= MinValue.y
				&& position.z <= MaxValue.z && position.x >= MinValue.z;
		}
	};
}