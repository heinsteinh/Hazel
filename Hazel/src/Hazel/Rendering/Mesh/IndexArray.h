#pragma once

#include "IndexFormatHelper.h"
#include "ByteArray.h"

namespace Hazel
{
	class IndexArray
	{
	private:
		IndexFormat indexFormat;
		ByteArray data;

	public:
		IndexArray(IndexFormat indexFormat = IndexFormat::UInt16)
			: indexFormat(indexFormat),
			data(IndexFormatHelper::GetSize(indexFormat))
		{
		}

		IndexFormat GetIndexFormat() const
		{
			return indexFormat;
		}

		void SetIndexFormat(IndexFormat indexFormat)
		{
			this->indexFormat = indexFormat;
			data.SetItemSize(IndexFormatHelper::GetSize(indexFormat));
			Clear();
		}

		const void *GetData() const
		{
			return data.GetData();
		}

		size_t GetSize() const
		{
			return data.GetSize();
		}

		size_t GetIndexSize() const
		{
			return data.GetItemSize();
		}

		size_t GetIndexCount() const
		{
			return data.GetItemCount();
		}

		void ReserveIndexCount(size_t indexCount)
		{
			data.ReserveItemCount(indexCount);
		}

		void ReserveSize(size_t size)
		{
			data.ReserveSize(size);
		}

		void Clear()
		{
			data.Clear();
		}

		template<typename IndexType>
		IndexType GetIndex(size_t index) const
		{
			return data.GetItem<IndexType>(index);
		}

		template<typename IndexType>
		IndexType &GetIndex(size_t index)
		{
			return data.GetItem<IndexType>(index);
		}

		template<typename IndexType>
		IndexType &AddIndex(size_t index)
		{
			return data.Emplace<IndexType>(static_cast<IndexType>(index));
		}

		template<typename IndexType, typename FunctorType>
		void ForEach(const FunctorType &functor) const
		{
			data.ForEach<IndexType>(functor);
		}

		template<typename IndexType, typename FunctorType>
		void ForEach(const FunctorType &functor)
		{
			data.ForEach<IndexType>(functor);
		}
	};
}