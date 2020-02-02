#pragma once

#include "ShaderDataType.h"

namespace Hazel
{
    class HAZEL_API BufferElement
    {
    private:
        ShaderDataType type = ShaderDataType::Float;
        std::string name;
        size_t offset = 0;
        bool normalized = false;

    public:
        BufferElement() = default;

        BufferElement(ShaderDataType type, const std::string &name, bool normalized = false)
            : type(type),
            name(name),
            normalized(normalized)
        {
        }

        inline ShaderDataType GetType() const
        {
            return type;
        }

        constexpr const std::string &GetName() const
        {
            return name;
        }

        constexpr size_t GetOffset() const
        {
            return offset;
        }

        constexpr bool IsNormalized() const
        {
            return normalized;
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