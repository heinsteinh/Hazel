#pragma once

#include "IndexFormatHelper.h"

namespace Hazel
{
	class IndexBuffer
	{
	private:
		size_t indexCount = 0;
		IndexFormat indexFormat = IndexFormat::UInt32;
		size_t size = 0;

	public:
		constexpr IndexBuffer(size_t indexCount, IndexFormat indexFormat)
			: indexCount(indexCount),
			indexFormat(indexFormat),
			size(IndexFormatHelper::GetSize(indexCount, indexFormat))
		{
		}

		virtual ~IndexBuffer() = default;

		virtual void BufferData(const void *data, size_t size) = 0;

		constexpr size_t GetIndexCount() const
		{
			return indexCount;
		}

		constexpr IndexFormat GetIndexFormat() const
		{
			return indexFormat;
		}

		constexpr size_t GetSize() const
		{
			return size;
		}
	};
}