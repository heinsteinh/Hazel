#pragma once

namespace Hazel
{
	template<typename T>
	class Reversed
	{
	private:
		T &iterable;

	public:
		constexpr Reversed(T &iterable)
			: iterable(iterable)
		{
		}

		auto begin()
		{
			return iterable.rbegin();
		}

		auto end()
		{
			return iterable.rend();
		}
	};
}