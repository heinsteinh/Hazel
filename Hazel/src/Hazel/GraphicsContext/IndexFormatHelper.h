#pragma once

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

		static constexpr size_t GetSize(size_t indexCount, IndexFormat indexFormat)
		{
			return indexCount * GetSize(indexFormat);
		}
	};
}