#pragma once

namespace Hazel
{
	template<typename ElementType>
	class BatchArray
	{
	private:
		size_t elementCount = 0;
		std::vector<ElementType> data;

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

		template<typename T>
		void AddWithCast(const T &element)
		{
			Add(static_cast<ElementType>(element));
		}

		void Add(const ElementType &element)
		{
			data[elementCount++] = element;
		}

		ElementType &Emplace()
		{
			return data[elementCount++];
		}

		const void *GetData() const
		{
			return data.data();
		}

		size_t GetSize() const
		{
			return elementCount * sizeof(ElementType);
		}
	};
}