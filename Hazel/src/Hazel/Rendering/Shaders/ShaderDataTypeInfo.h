#pragma once

#include "Hazel/Core/DataTypeInfo.h"
#include "ShaderDataType.h"

namespace Hazel
{
    class ShaderDataTypeInfo
    {
    private:
        ShaderDataType type;

    public:
        constexpr ShaderDataTypeInfo(ShaderDataType type)
            : type(type)
        {
        }

        constexpr DataType GetComponentType() const
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
            default:
                return DataType::Unknown;
            }
        }

        constexpr size_t GetComponentCount() const
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

        constexpr size_t GetComponentSize() const
        {
            return DataTypeInfo::GetSize(GetComponentType());
        }

        constexpr size_t GetSize() const
        {
            return GetComponentCount() * GetComponentSize();
        }

        constexpr operator ShaderDataType() const
        {
            return type;
        }
    };
}