#pragma once

#include "DataType.h"

namespace Hazel
{
	class DataTypeHelper
	{
	public:
		static constexpr size_t GetSize(DataType dataType)
		{
			switch (dataType)
			{
			case DataType::Bool:
				return 1;
			case DataType::Int:
				return 4;
			case DataType::Float:
				return 4;
			default:
				return 0;
			}
		}
	};
}