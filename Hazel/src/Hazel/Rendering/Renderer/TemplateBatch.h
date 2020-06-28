#pragma once

namespace Hazel
{
	template<typename T>
	class TemplateBatch
	{
	private:
		size_t size = 0;
		std::vector<T> data;

	public:
		TemplateBatch(size_t max)
			: data(max)
		{
		}

		constexpr size_t GetSize() const
		{
			return size;
		}

		inline const T *GetData() const
		{
			return data.data();
		}

		constexpr void Clear()
		{
			size = 0;
		}

		inline T &Add(const T &item)
		{
			assert(size < data.size());
			return data[size++] = item;
		}
	};
}