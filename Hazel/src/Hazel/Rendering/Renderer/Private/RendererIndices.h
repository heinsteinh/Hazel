#pragma once

#include "Hazel/Rendering/Mesh/IndexFormatHelper.h"
#include "Hazel/Rendering/Mesh/ByteArray.h"

namespace Hazel
{
	class RendererIndices
	{
	private:
		size_t indexCount = 0;
		IndexFormat indexFormat = IndexFormat::UInt16;
		ByteArray data;

	public:
		RendererIndices() = default;

		RendererIndices(IndexFormat indexFormat, size_t size)
			: indexFormat(indexFormat),
			data(IndexFormatHelper::GetSize(indexFormat))
		{
			Resize(size);
		}

		IndexFormat GetIndexFormat() const
		{
			return indexFormat;
		}

		size_t GetIndexCount() const
		{
			return indexCount;
		}

		void Clear()
		{
			indexCount = 0;
		}

		const void *GetData() const
		{
			return data.GetData();
		}

		size_t GetSize() const
		{
			return indexCount * data.GetItemSize();
		}

		void Resize(size_t size)
		{
			data.Resize(size);
		}

		bool CanContain(size_t indexCount) const
		{
			return GetIndexCount() + indexCount <= GetMaxIndexCount();
		}

		size_t GetMaxIndexCount() const
		{
			return data.GetItemCount();
		}

		size_t GetIndexSize() const
		{
			return data.GetItemSize();
		}

		template<typename IndexType>
		IndexType &Add(size_t index)
		{
			HZ_ASSERT(CanContain(1), "Buffer too small");
			HZ_ASSERT(sizeof(IndexType) == GetIndexSize(), "Index format mismatch");
			return data.GetItem<IndexType>(indexCount++) = static_cast<IndexType>(index);
		}
	};
}