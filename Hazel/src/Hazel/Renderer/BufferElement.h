#pragma once

#include "ShaderDataType.h"

namespace Hazel
{
    class HAZEL_API BufferElement
    {
    private:
        const ShaderDataType *type;
        std::string name;
        size_t offset = 0;
        bool normalized = false;

    public:
        BufferElement() = default;

        BufferElement(const ShaderDataType &type, const std::string &name, bool normalized = false)
            : type(&type),
            name(name),
            normalized(normalized)
        {
        }

        inline void SetOffset(size_t offset)
        {
            this->offset = offset;
        }

        inline const ShaderDataType &GetType() const
        {
            return *type;
        }

        inline const std::string &GetName() const
        {
            return name;
        }

        inline size_t GetOffset() const
        {
            return offset;
        }

        inline bool IsNormalized() const
        {
            return normalized;
        }

        inline size_t GetComponentSize() const
        {
            return type->GetComponentSize();
        }

        inline size_t GetComponentCount() const
        {
            return type->GetComponentCount();
        }

        inline size_t GetSize() const
        {
            return type->GetSize();
        }
    };
}