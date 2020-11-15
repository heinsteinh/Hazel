#pragma once

#include "Hazel/Buffers/IndexFormatHelper.h"
#include "BatchArray.h"

namespace Hazel
{
	class BatchIndices
	{
	private:
		IndexFormat format;
		BatchArray data;

	public:
		inline BatchIndices(size_t size = 0, IndexFormat format = IndexFormat::UInt32)
			: format(format),
			data(IndexFormatHelper::GetSize(format), size)
		{
		}

		inline size_t GetMaxElementCount() const
		{
			return data.GetMaxElementCount();
		}

		inline void SetMaxElementCount(size_t count)
		{
			data.SetMaxElementCount(count);
		}

		inline size_t GetElementCount() const
		{
			return data.GetElementCount();
		}

		inline void SetElementCount(size_t elementCount)
		{
			data.SetElementCount(elementCount);
		}

		inline void Clear()
		{
			data.Clear();
		}

		inline bool CanContain(size_t elementCount) const
		{
			return data.CanContain(elementCount);
		}

		inline void *Add(uint32_t index)
		{
			switch (format)
			{
			case IndexFormat::UInt8:
				return AddIndex<uint8_t>(index);
			case IndexFormat::UInt16:
				return AddIndex<uint16_t>(index);
			case IndexFormat::UInt32:
				return AddIndex<uint32_t>(index);
			}
			HZ_ASSERT(false, "Invalid index format");
		}

		inline const void *GetData() const
		{
			return data.GetData();
		}

		inline size_t GetSize() const
		{
			return data.GetSize();
		}

	private:
		template<typename IndexType>
		void *AddIndex(uint32_t index)
		{
			auto value = static_cast<IndexType>(index);
			return data.Add(&value);
		}
	};
}