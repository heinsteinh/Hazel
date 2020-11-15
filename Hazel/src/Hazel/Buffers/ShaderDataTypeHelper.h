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
			case ShaderDataType::Matrix3:
			case ShaderDataType::Matrix4:
				return DataType::Float;
			case ShaderDataType::Integer:
			case ShaderDataType::Integer2:
			case ShaderDataType::Integer3:
			case ShaderDataType::Integer4:
				return DataType::Integer;
			case ShaderDataType::Bool:
				return DataType::Bool;
			}
			return DataType::Unknown;
		}

		static constexpr size_t GetComponentCount(ShaderDataType type)
		{
			switch (type)
			{
			case ShaderDataType::Float:
			case ShaderDataType::Integer:
			case ShaderDataType::Bool:
				return 1;
			case ShaderDataType::Float2:
			case ShaderDataType::Integer2:
				return 2;
			case ShaderDataType::Float3:
			case ShaderDataType::Integer3:
				return 3;
			case ShaderDataType::Float4:
			case ShaderDataType::Integer4:
				return 4;
			case ShaderDataType::Matrix3:
				return 9;
			case ShaderDataType::Matrix4:
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