#pragma once

#include "ShaderDataType.h"
#include "DataTypeHelper.h"

namespace Hazel
{
	class ShaderDataTypeHelper
	{
	public:
		static constexpr DataType GetComponentType(ShaderDataType type)
		{
			switch (type)
			{
			case ShaderDataType::Float:
			case ShaderDataType::Float2:
			case ShaderDataType::Float3:
			case ShaderDataType::Float4:
			case ShaderDataType::Mat3:
			case ShaderDataType::Mat4:
				return DataType::Float;
			case ShaderDataType::Int:
			case ShaderDataType::Int2:
			case ShaderDataType::Int3:
			case ShaderDataType::Int4:
				return DataType::Int;
			case ShaderDataType::Bool:
				return DataType::Bool;
			default:
				return DataType::Unknown;
			}
		}

		static constexpr size_t GetComponentCount(ShaderDataType type)
		{
			switch (type)
			{
			case ShaderDataType::Float:
			case ShaderDataType::Int:
			case ShaderDataType::Bool:
				return 1;
			case ShaderDataType::Float2:
			case ShaderDataType::Int2:
				return 2;
			case ShaderDataType::Float3:
			case ShaderDataType::Int3:
				return 3;
			case ShaderDataType::Float4:
			case ShaderDataType::Int4:
				return 4;
			case ShaderDataType::Mat3:
				return 9;
			case ShaderDataType::Mat4:
				return 16;
			default:
				return 0;
			}
		}

		static constexpr size_t GetComponentSize(ShaderDataType type)
		{
			return DataTypeHelper::GetSize(GetComponentType(type));
		}

		static constexpr size_t GetSize(ShaderDataType type)
		{
			return GetComponentCount(type) * GetComponentSize(type);
		}
	};
}