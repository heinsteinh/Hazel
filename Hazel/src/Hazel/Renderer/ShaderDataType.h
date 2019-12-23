#pragma once

#include "Hazel/Core/Core.h"

namespace Hazel
{
    class ShaderDataType
    {
    public:
        static const ShaderDataType Float;
        static const ShaderDataType Float2;
        static const ShaderDataType Float3;
        static const ShaderDataType Float4;
        static const ShaderDataType Matrix3;
        static const ShaderDataType Matrix4;
        static const ShaderDataType Int;
        static const ShaderDataType Int2;
        static const ShaderDataType Int3;
        static const ShaderDataType Int4;
        static const ShaderDataType Bool;

    private:
        size_t componentSize = 0;
        size_t componentCount = 0;
        size_t size = 0;

    public:
        ShaderDataType(const ShaderDataType &other) = delete;
        ShaderDataType &operator=(const ShaderDataType &other) = delete;

        inline size_t GetComponentSize() const
        {
            return componentSize;
        }

        inline size_t GetComponentCount() const
        {
            return componentCount;
        }

        inline size_t GetSize() const
        {
            return size;
        }

        inline bool operator==(const ShaderDataType &other) const
        {
            return this == &other;
        }

    private:
        constexpr ShaderDataType(size_t componentSize, size_t componentCount)
            : componentSize(componentSize),
            componentCount(componentCount),
            size(componentSize *componentCount)
        {
        }
    };
}