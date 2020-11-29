#pragma once

namespace Hazel
{
	class Clamper
	{
	public:
		template<typename T>
		static constexpr T Clamp(T position, std::optional<T> min, std::optional<T> max)
		{
			if (min && position < min)
			{
				return min.value();
			}
			else if (max && position > max)
			{
				return max.value();
			}
			return position;
		}
	};
}