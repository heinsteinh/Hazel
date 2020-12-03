#include "BatchIndices.h"

namespace Hazel
{
	BatchIndices::BatchIndices(size_t maxIndexCount, IndexFormat format)
		: format(format)
	{
		SetMaxIndexCount(maxIndexCount);
	}

	size_t BatchIndices::GetMaxIndexCount() const
	{
		switch (format)
		{
		case IndexFormat::UInt8:
			return data8.GetMaxElementCount();
		case IndexFormat::UInt16:
			return data16.GetMaxElementCount();
		case IndexFormat::UInt32:
			return data32.GetMaxElementCount();
		}
		HZ_ASSERT(false, "Invalid index format");
	}

	void BatchIndices::SetMaxIndexCount(size_t maxIndexCount)
	{
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

	size_t BatchIndices::GetIndexCount() const
	{
		switch (format)
		{
		case IndexFormat::UInt8:
			return data8.GetElementCount();
		case IndexFormat::UInt16:
			return data16.GetElementCount();
		case IndexFormat::UInt32:
			return data32.GetElementCount();
		}
		HZ_ASSERT(false, "Invalid index format");
	}

	void BatchIndices::SetIndexCount(size_t indexCount)
	{
		switch (format)
		{
		case IndexFormat::UInt8:
			return data8.SetElementCount(indexCount);
		case IndexFormat::UInt16:
			return data16.SetElementCount(indexCount);
		case IndexFormat::UInt32:
			return data32.SetElementCount(indexCount);
		}
		HZ_ASSERT(false, "Invalid index format");
	}

	void BatchIndices::Clear()
	{
		switch (format)
		{
		case IndexFormat::UInt8:
			return data8.Clear();
		case IndexFormat::UInt16:
			return data16.Clear();
		case IndexFormat::UInt32:
			return data32.Clear();
		}
		HZ_ASSERT(false, "Invalid index format");
	}

	bool BatchIndices::CanContain(size_t indexCount) const
	{
		return GetIndexCount() + indexCount <= GetMaxIndexCount();
	}

	void BatchIndices::Add(uint32_t index)
	{
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

	const void *BatchIndices::GetData() const
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

	size_t BatchIndices::GetSize() const
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
}