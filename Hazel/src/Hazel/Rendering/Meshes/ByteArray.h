#pragma once

#include <vector>

#include "Hazel/Core/Exceptions/AssertionException.h"

namespace Hazel
{
	class ByteArray
	{
	private:
		size_t itemSize = 0;
		std::vector<char> data;

	public:
		ByteArray() = default;

		ByteArray(size_t itemSize, size_t itemCount = 0)
			: itemSize(itemSize),
			data(itemSize *itemCount)
		{
		}

		size_t GetItemSize() const
		{
			return itemSize;
		}

		void SetItemSize(size_t itemSize)
		{
			this->itemSize = itemSize;
		}

		const void *GetData() const
		{
			return data.data();
		}

		void *GetData()
		{
			return data.data();
		}

		size_t GetSize() const
		{
			return data.size();
		}

		void Resize(size_t size)
		{
			data.resize(size);
		}

		size_t GetItemCount() const
		{
			return data.size() / itemSize;
		}

		void SetItemCount(size_t itemCount)
		{
			data.resize(itemCount * itemSize);
		}

		void Clear()
		{
			data.clear();
		}

		void Reserve(size_t itemCount)
		{
			data.reserve(itemCount * itemSize);
		}

		void ReserveSize(size_t size)
		{
			data.reserve(size);
		}

		const void *GetItem(size_t index) const
		{
			HZ_ASSERT(index < GetItemCount(), "Index out of range");
			return data.data() + index * itemSize;
		}

		void *GetItem(size_t index)
		{
			HZ_ASSERT(index < GetItemCount(), "Index out of range");
			return data.data() + index * itemSize;
		}

		void *SetItem(size_t index, const void *item)
		{
			return std::memcpy(GetItem(index), item, itemSize);
		}

		void *AddItem(const void *item)
		{
			std::memcpy(AddItem(), item, itemSize);
			return data.data();
		}

		void *AddItem()
		{
			auto oldSize = data.size();
			data.resize(oldSize + itemSize);
			return data.data() + oldSize;
		}

		template<typename T>
		const T &GetItem(size_t index) const
		{
			return *static_cast<const T *>(GetItem(index));
		}

		template<typename T>
		T &GetItem(size_t index)
		{
			return *static_cast<T *>(GetItem(index));
		}

		template<typename T, typename ...Args>
		T &Construct(size_t index, Args &&...args)
		{
			HZ_ASSERT(sizeof(T) == itemSize, "Type does not match item size");
			return *new(GetItem(index)) T(std::forward<Args>(args)...);
		}

		template<typename T, typename ...Args>
		T &Emplace(Args &&...args)
		{
			AddItem();
			return Construct<T>(GetItemCount() - 1, std::forward<Args>(args)...);
		}

		template<typename FunctorType>
		void ForEach(FunctorType functor) const
		{
			auto itemCount = GetItemCount();
			for (size_t i = 0; i < itemCount; i++)
			{
				functor(GetItem(i));
			}
		}

		template<typename FunctorType>
		void ForEach(FunctorType functor)
		{
			auto itemCount = GetItemCount();
			for (size_t i = 0; i < itemCount; i++)
			{
				functor(GetItem(i));
			}
		}

		template<typename ItemType, typename FunctorType>
		void ForEach(FunctorType functor) const
		{
			auto itemCount = GetItemCount();
			for (size_t i = 0; i < itemCount; i++)
			{
				functor(GetItem<ItemType>(i));
			}
		}

		template<typename ItemType, typename FunctorType>
		void ForEach(FunctorType functor)
		{
			auto itemCount = GetItemCount();
			for (size_t i = 0; i < itemCount; i++)
			{
				functor(GetItem<ItemType>(i));
			}
		}
	};
}