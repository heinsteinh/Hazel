#pragma once

#include "IndexFormat.h"

namespace Hazel
{
	class IndexFormatHelper
	{
	public:
		static constexpr size_t GetSize(IndexFormat format)
		{
			switch (format)
			{
			case IndexFormat::UInt8:
				return 1;
			case IndexFormat::UInt16:
				return 2;
			case IndexFormat::UInt32:
				return 3;
			}
			return 0;
		}
	};
}