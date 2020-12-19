#pragma once

namespace Hazel
{
	class Size
	{
	public:
		static constexpr float GetArea(const glm::vec2 &size)
		{
			return size.x * size.y;
		}

		static constexpr float GetAspectRatio(const glm::vec2 &size)
		{
			return size.y ? size.x / size.y : 0.0f;
		}

		static constexpr bool IsEmpty(const glm::vec2 &size)
		{
			return size.x == 0.0f || size.y == 0.0f;
		}
	};
}