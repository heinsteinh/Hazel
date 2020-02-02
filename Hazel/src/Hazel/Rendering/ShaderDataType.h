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
        DataType componentType = DataType::Float;
        unsigned short componentCount = 0;

    public:
        constexpr ShaderDataType(const ShaderDataType &other) = default;

        constexpr size_t GetHashCode() const
        {
            return componentType.GetHashCode() ^ componentCount;
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

        constexpr ShaderDataType &operator=(const ShaderDataType &other) = default;

        constexpr bool operator==(const ShaderDataType &other) const
        {
            return componentType == other.componentType && componentCount == other.componentCount;
        }

    private:
        inline ShaderDataType(DataType componentType, size_t componentCount)
            : componentType(componentType),
            componentCount(static_cast<unsigned short>(componentCount))
        {
        }
    };

    inline const ShaderDataType ShaderDataType::Float(DataType::Float, 1);
    inline const ShaderDataType ShaderDataType::Float2(DataType::Float, 2);
    inline const ShaderDataType ShaderDataType::Float3(DataType::Float, 3);
    inline const ShaderDataType ShaderDataType::Float4(DataType::Float, 4);
    inline const ShaderDataType ShaderDataType::Matrix3(DataType::Float, 9);
    inline const ShaderDataType ShaderDataType::Matrix4(DataType::Float, 16);
    inline const ShaderDataType ShaderDataType::Integer(DataType::Integer, 1);
    inline const ShaderDataType ShaderDataType::Integer2(DataType::Integer, 2);
    inline const ShaderDataType ShaderDataType::Integer3(DataType::Integer, 3);
    inline const ShaderDataType ShaderDataType::Integer4(DataType::Integer, 4);
    inline const ShaderDataType ShaderDataType::Bool(DataType::Bool, 1);
}

namespace std
{
    template<>
    struct hash<Hazel::ShaderDataType>
    {
        constexpr size_t operator()(const Hazel::ShaderDataType &shaderDataType) const
        {
            return shaderDataType.GetHashCode();
        }
    };
}