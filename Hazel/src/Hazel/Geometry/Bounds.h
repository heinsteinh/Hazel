#pragma once

namespace Hazel
{
	struct Bounds
	{
		glm::vec3 MinValue = {-1.0f, -1.0f, -1.0f};
		glm::vec3 MaxValue = {1.0f, 1.0f, 1.0f};

		constexpr glm::vec3 Clamp(const glm::vec3 &position) const
		{
			return glm::clamp(position, MinValue, MaxValue);
		}

		constexpr glm::vec2 Clamp(const glm::vec2 &position) const
		{
			return {glm::clamp(position.x, MinValue.x, MaxValue.x),
				glm::clamp(position.y, MinValue.y, MaxValue.y)};
		}

		constexpr float ClampX(float position) const
		{
			return glm::clamp(position, MinValue.x, MaxValue.x);
		}

		constexpr float ClampY(float position) const
		{
			return glm::clamp(position, MinValue.y, MaxValue.y);
		}

		constexpr float ClampZ(float position) const
		{
			return glm::clamp(position, MinValue.z, MaxValue.z);
		}

		constexpr bool Contains(const glm::vec3 &position) const
		{
			return position.x <= MaxValue.x && position.x >= MinValue.x
				&& position.y <= MaxValue.y && position.y >= MinValue.y
				&& position.z <= MaxValue.z && position.x >= MinValue.z;
		}

		constexpr bool Contains(const glm::vec2 &position) const
		{
			return position.x <= MaxValue.x && position.x >= MinValue.x
				&& position.y <= MaxValue.y && position.y >= MinValue.y;
		}

		constexpr bool ContainsX(float position) const
		{
			return position <= MaxValue.x && position >= MinValue.x;
		}

		constexpr bool ContainsY(float position) const
		{
			return position <= MaxValue.y && position >= MinValue.y;
		}

		constexpr bool ContainsZ(float position) const
		{
			return position <= MaxValue.z && position >= MinValue.z;
		}
	};
}