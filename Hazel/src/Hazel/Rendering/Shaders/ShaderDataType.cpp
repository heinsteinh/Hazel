#include "ShaderDataType.h"

namespace Hazel
{
    const ShaderDataType ShaderDataType::Float(DataType::Float, 1);
    const ShaderDataType ShaderDataType::Float2(DataType::Float, 2);
    const ShaderDataType ShaderDataType::Float3(DataType::Float, 3);
    const ShaderDataType ShaderDataType::Float4(DataType::Float, 4);
    const ShaderDataType ShaderDataType::Matrix3(DataType::Float, 9);
    const ShaderDataType ShaderDataType::Matrix4(DataType::Float, 16);
    const ShaderDataType ShaderDataType::Integer(DataType::Integer, 1);
    const ShaderDataType ShaderDataType::Integer2(DataType::Integer, 2);
    const ShaderDataType ShaderDataType::Integer3(DataType::Integer, 3);
    const ShaderDataType ShaderDataType::Integer4(DataType::Integer, 4);
    const ShaderDataType ShaderDataType::Bool(DataType::Bool, 1);

    ShaderDataType::ShaderDataType(DataType componentType, size_t componentCount)
        : componentType(componentType),
        componentCount(static_cast<unsigned short>(componentCount))
    {
    }
}