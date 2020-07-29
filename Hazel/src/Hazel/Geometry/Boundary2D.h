#pragma once

namespace Hazel
{
	struct Boundary2D
	{
		glm::vec2 MinValue = {-1.0f, -1.0f};
		glm::vec2 MaxValue = {1.0f, 1.0f};

		constexpr glm::vec2 Clamp(const glm::vec2 &position) const
		{
			return glm::clamp(position, MinValue, MaxValue);
		}

		constexpr bool Contains(const glm::vec2 &position) const
		{
			return position.x <= MaxValue.x && position.x >= MinValue.x
				&& position.y <= MaxValue.y && position.y >= MinValue.y;
		}
	};
}