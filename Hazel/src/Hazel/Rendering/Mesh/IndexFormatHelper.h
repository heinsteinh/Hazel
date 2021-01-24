#pragma once

#include <cstdint>

#include "IndexFormat.h"

namespace Hazel
{
	class IndexFormatHelper
	{
	public:
		static constexpr size_t GetSize(IndexFormat indexFormat)
		{
			switch (indexFormat)
			{
			case IndexFormat::UInt8:
				return 1;
			case IndexFormat::UInt16:
				return 2;
			case IndexFormat::UInt32:
				return 4;
			}
			return 0;
		}

		template<typename IndexType>
		static constexpr IndexFormat GetIndexFormat()
		{
			static_assert(false, "Invalid index type");
		}

		template<>
		static constexpr IndexFormat GetIndexFormat<uint8_t>()
		{
			return IndexFormat::UInt8;
		}

		template<>
		static constexpr IndexFormat GetIndexFormat<uint16_t>()
		{
			return IndexFormat::UInt16;
		}

		template<>
		static constexpr IndexFormat GetIndexFormat<uint32_t>()
		{
			return IndexFormat::UInt32;
		}
	};
}