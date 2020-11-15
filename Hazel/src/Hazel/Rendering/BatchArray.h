#pragma once

namespace Hazel
{
	class BatchArray
	{
	private:
		size_t elementCount = 0;
		size_t elementSize = 0;
		std::vector<char> data;

	public:
		inline BatchArray(size_t elementSize, size_t maxElementCount = 0)
			: elementSize(elementSize),
			data(maxElementCount *elementSize)
		{
		}

		inline size_t GetMaxElementCount() const
		{
			return data.size() / elementSize;
		}

		inline void SetMaxElementCount(size_t count)
		{
			data.resize(count * elementSize);
		}

		inline size_t GetElementCount() const
		{
			return elementCount;
		}

		inline void SetElementCount(size_t elementCount)
		{
			this->elementCount = elementCount;
		}

		inline void Clear()
		{
			elementCount = 0;
		}

		inline bool CanContain(size_t elementCount) const
		{
			return this->elementCount + elementCount <= GetMaxElementCount();
		}

		inline void *Add(const void *element)
		{
			HZ_ASSERT(CanContain(1), "Not enough space.");
			return std::memcpy(data.data() + elementCount++ * elementSize, element, elementSize);
		}

		inline const void *GetData() const
		{
			return data.data();
		}

		inline size_t GetSize() const
		{
			return data.size();
		}
	};
}