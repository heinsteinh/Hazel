#include "BatchIndices.h"

#define HZ_INVALID_FORMAT() HZ_ASSERT(false, "Invalid index format")

#define HZ_FORWARD(method, ...) switch (format) \
		{ \
		case IndexFormat::UInt8: \
			return data8.method(__VA_ARGS__); \
		case IndexFormat::UInt16: \
			return data16.method(__VA_ARGS__); \
		case IndexFormat::UInt32: \
			return data32.method(__VA_ARGS__); \
		} \
		HZ_INVALID_FORMAT()

namespace Hazel
{
	BatchIndices::BatchIndices(size_t maxIndexCount, IndexFormat format)
		: format(format)
	{
		SetMaxIndexCount(maxIndexCount);
	}

	size_t BatchIndices::GetMaxIndexCount() const
	{
		HZ_FORWARD(GetMaxElementCount);
	}

	void BatchIndices::SetMaxIndexCount(size_t maxIndexCount)
	{
		HZ_FORWARD(SetMaxElementCount, maxIndexCount);
	}

	size_t BatchIndices::GetIndexCount() const
	{
		HZ_FORWARD(GetElementCount);
	}

	void BatchIndices::SetIndexCount(size_t indexCount)
	{
		HZ_FORWARD(SetElementCount, indexCount);
	}

	void BatchIndices::Clear()
	{
		HZ_FORWARD(Clear);
	}

	bool BatchIndices::CanContain(size_t indexCount) const
	{
		return GetIndexCount() + indexCount <= GetMaxIndexCount();
	}

	void BatchIndices::Add(uint32_t index)
	{
		HZ_FORWARD(AddWithCast, index);
	}

	const void *BatchIndices::GetData() const
	{
		HZ_FORWARD(GetData);
	}

	size_t BatchIndices::GetSize() const
	{
		HZ_FORWARD(GetSize);
	}
}