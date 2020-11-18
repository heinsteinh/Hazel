#pragma once

namespace Hazel
{
	template<typename T>
	class BatchArray
	{
	private:
		size_t elementCount = 0;
		std::vector<T> data;

	public:
		BatchArray() = default;

		BatchArray(size_t maxElementCount)
			: data(maxElementCount)
		{
		}

		size_t GetMaxElementCount() const
		{
			return data.size();
		}

		void SetMaxElementCount(size_t maxElementCount)
		{
			data.resize(maxElementCount);
		}

		size_t GetElementCount() const
		{
			return elementCount;
		}

		void SetElementCount(size_t elementCount)
		{
			this->elementCount = elementCount;
		}

		void Clear()
		{
			elementCount = 0;
		}

		bool CanContain(size_t elementCount) const
		{
			return this->elementCount + elementCount <= GetMaxElementCount();
		}

		void Add(const T &element)
		{
			data[elementCount++] = element;
		}

		T &Emplace()
		{
			return data[elementCount++];
		}

		const void *GetData() const
		{
			return data.data();
		}

		size_t GetSize() const
		{
			return elementCount * sizeof(T);
		}
	};
}