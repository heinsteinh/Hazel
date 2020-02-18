#pragma once

#include "Hazel/Rendering/Shaders/ShaderDataTypeInfo.h"

namespace Hazel
{
    class HAZEL_API BufferElement
    {
    private:
        std::string name;
        ShaderDataTypeInfo type = ShaderDataType::Unknown;
        size_t offset = 0;
        bool normalized = false;

    public:
        BufferElement() = default;

        BufferElement(const std::string &name, ShaderDataType type, bool normalized = false)
            : name(name),
            type(type),
            normalized(normalized)
        {
        }

        constexpr const std::string &GetName() const
        {
            return name;
        }

        inline ShaderDataType GetType() const
        {
            return type;
        }

        constexpr size_t GetOffset() const
        {
            return offset;
        }

        constexpr bool IsNormalized() const
        {
            return normalized;
        }

        constexpr DataType GetComponentType() const
        {
            return type.GetComponentType();
        }

        constexpr size_t GetComponentSize() const
        {
            return type.GetComponentSize();
        }

        constexpr size_t GetComponentCount() const
        {
            return type.GetComponentCount();
        }

        constexpr size_t GetSize() const
        {
            return type.GetSize();
        }

        constexpr void SetOffset(size_t offset)
        {
            this->offset = offset;
        }
    };
}