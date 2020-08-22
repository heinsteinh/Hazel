#pragma once

#include "glad/glad.h"

#include "Hazel/Buffers/DataType.h"

namespace Hazel
{
	class OpenGLDataType
	{
	public:
		static constexpr uint32_t FromDataType(DataType dataType)
		{
			switch (dataType)
			{
			case DataType::Float:
				return GL_FLOAT;
			case DataType::Integer:
				return GL_INT;
			case DataType::Bool:
				return GL_BOOL;
			}
			return 0;
		}

		OpenGLDataType() = delete;
	};
}