#pragma once

#include "Hazel/Buffers/IndexFormatHelper.h"
#include "BatchArray.h"
#include "Hazel/Exceptions/AssertionException.h"

namespace Hazel
{
	class BatchIndices
	{
	private:
		IndexFormat format;
		size_t indexCount = 0;
		size_t maxIndexCount;
		BatchArray<uint8_t> data8;
		BatchArray<uint16_t> data16;
		BatchArray<uint32_t> data32;

	public:
		inline BatchIndices(size_t maxIndexCount = 0, IndexFormat format = IndexFormat::UInt32)
			: format(format)
		{
			SetMaxIndexCount(maxIndexCount);
		}

		inline size_t GetMaxIndexCount() const
		{
			return maxIndexCount;
		}

		inline void SetMaxIndexCount(size_t maxIndexCount)
		{
			this->maxIndexCount = maxIndexCount;
			switch (format)
			{
			case IndexFormat::UInt8:
				return data8.SetMaxElementCount(maxIndexCount);
			case IndexFormat::UInt16:
				return data16.SetMaxElementCount(maxIndexCount);
			case IndexFormat::UInt32:
				return data32.SetMaxElementCount(maxIndexCount);
			}
			HZ_ASSERT(false, "Invalid index format");
		}

		inline size_t GetIndexCount() const
		{
			return indexCount;
		}

		inline void SetIndexCount(size_t indexCount)
		{
			this->indexCount = indexCount;
		}

		inline void Clear()
		{
			indexCount = 0;
		}

		inline bool CanContain(size_t indexCount) const
		{
			return this->indexCount + indexCount <= maxIndexCount;
		}

		inline void Add(uint32_t index)
		{
			indexCount++;
			switch (format)
			{
			case IndexFormat::UInt8:
				return data8.Add(static_cast<uint8_t>(index));
			case IndexFormat::UInt16:
				return data16.Add(static_cast<uint16_t>(index));
			case IndexFormat::UInt32:
				return data32.Add(index);
			}
			HZ_ASSERT(false, "Invalid index format");
		}

		inline const void *GetData() const
		{
			switch (format)
			{
			case IndexFormat::UInt8:
				return data8.GetData();
			case IndexFormat::UInt16:
				return data16.GetData();
			case IndexFormat::UInt32:
				return data32.GetData();
			}
			HZ_ASSERT(false, "Invalid index format");
		}

		inline size_t GetSize() const
		{
			switch (format)
			{
			case IndexFormat::UInt8:
				return data8.GetSize();
			case IndexFormat::UInt16:
				return data16.GetSize();
			case IndexFormat::UInt32:
				return data32.GetSize();
			}
			HZ_ASSERT(false, "Invalid index format");
		}
	};
}