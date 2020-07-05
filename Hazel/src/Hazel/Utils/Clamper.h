#pragma once

namespace Hazel
{
	class Clamper
	{
	public:
		template<typename T>
		static constexpr void Clamp(T &value, std::optional<T> minValue, std::optional<T> maxValue)
		{
			if (minValue && value < minValue.value())
			{
				value = minValue.value();
			}
			else if (maxValue && value > maxValue.value())
			{
				value = maxValue.value();
			}
		}

		Clamper() = delete;
	};
}