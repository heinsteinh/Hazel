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
			case DataType::Integer:
				return sizeof(int);
			case DataType::Float:
				return sizeof(float);
			default:
				return 0;
			}
		}

		DataTypeHelper() = delete;
	};
}