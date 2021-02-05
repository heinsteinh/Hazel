#pragma once

#include <array>

namespace Hazel
{
	template<typename EnumType, typename ValueType>
	class EnumMap
	{
	private:
		std::array<ValueType, static_cast<size_t>(EnumType::Count)> data;

	public:
		EnumMap() = default;

		EnumMap(std::initializer_list<std::pair<EnumType, ValueType>> args)
		{
			for (const auto &[key, value] : args)
			{
				(*this)[key] = value;
			}
		}

		const ValueType &operator[](EnumType key) const
		{
			return data[static_cast<size_t>(key)];
		}

		ValueType &operator[](EnumType key)
		{
			return data[static_cast<size_t>(key)];
		}

		template<typename FunctorType>
		void ForEach(FunctorType functor) const
		{
			for (size_t i = 0; i < data.size(); i++)
			{
				functor(static_cast<EnumType>(i), data[i]);
			}
		}

		template<typename FunctorType>
		void ForEach(FunctorType functor)
		{
			for (size_t i = 0; i < data.size(); i++)
			{
				functor(static_cast<EnumType>(i), data[i]);
			}
		}
	};
}