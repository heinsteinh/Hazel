#pragma once

#include "Hazel/Core/DataType.h"

namespace Hazel
{
    class HAZEL_API ShaderDataType
    {
    public:
        static const ShaderDataType Float;
        static const ShaderDataType Float2;
        static const ShaderDataType Float3;
        static const ShaderDataType Float4;
        static const ShaderDataType Matrix3;
        static const ShaderDataType Matrix4;
        static const ShaderDataType Integer;
        static const ShaderDataType Integer2;
        static const ShaderDataType Integer3;
        static const ShaderDataType Integer4;
        static const ShaderDataType Bool;

    private:
        DataType componentType;
        unsigned short componentCount = 0;

    public:
        inline size_t GetHashCode() const
        {
            return componentType.GetHashCode() ^ std::hash<short>()(componentCount);
        }

        inline DataType GetComponentType() const
        {
            return componentType;
        }

        constexpr size_t GetComponentSize() const
        {
            return componentType.GetSize();
        }

        constexpr size_t GetComponentCount() const
        {
            return static_cast<size_t>(componentCount);
        }

        constexpr size_t GetSize() const
        {
            return componentCount * GetComponentSize();
        }

        constexpr bool operator==(const ShaderDataType &other) const
        {
            return componentType == other.componentType && componentCount == other.componentCount;
        }

        constexpr bool operator!=(const ShaderDataType &other) const
        {
            return componentType != other.componentType || componentCount != other.componentCount;
        }

    private:
        ShaderDataType(DataType componentType, size_t componentCount);
    };
}

namespace std
{
    template<>
    struct hash<Hazel::ShaderDataType>
    {
        inline size_t operator()(Hazel::ShaderDataType shaderDataType) const
        {
            return shaderDataType.GetHashCode();
        }
    };
}