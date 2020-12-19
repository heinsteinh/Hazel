#pragma once

namespace Hazel
{
	class Range
	{
	public:
		template<typename T>
		static constexpr bool Contains(T value, T min, T max)
		{
			return min >= max || value >= min && value <= max;
		}

		template<typename T>
		static constexpr T Clamp(T value, T min, T max)
		{
			return min >= max ? value : std::clamp(value, min, max);
		}
	};
}