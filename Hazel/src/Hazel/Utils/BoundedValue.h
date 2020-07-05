#pragma once

#include "Clamper.h"

namespace Hazel
{
	template<typename T>
	class BoundedValue
	{
	private:
		T value;
		std::optional<T> minValue;
		std::optional<T> maxValue;

	public:
		constexpr BoundedValue(T value, std::optional<T> minValue = {}, std::optional<T> maxValue = {})
			: value(value),
			minValue(minValue),
			maxValue(maxValue)
		{
			CheckValue();
		}

		constexpr BoundedValue &operator=(T value)
		{
			this->value = value;
			CheckValue();
		}

		constexpr operator T() const
		{
			return value;
		}

	private:
		constexpr void CheckValue()
		{
			Clamper::Clamp(value, minValue, maxValue);
		}
	};
}