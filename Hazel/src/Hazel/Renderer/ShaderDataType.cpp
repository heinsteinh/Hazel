#include "ShaderDataType.h"

namespace Hazel
{
    const ShaderDataType ShaderDataType::Float(sizeof(float), 1);
    const ShaderDataType ShaderDataType::Float2(sizeof(float), 2);
    const ShaderDataType ShaderDataType::Float3(sizeof(float), 3);
    const ShaderDataType ShaderDataType::Float4(sizeof(float), 4);
    const ShaderDataType ShaderDataType::Matrix3(sizeof(float), 9);
    const ShaderDataType ShaderDataType::Matrix4(sizeof(float), 16);
    const ShaderDataType ShaderDataType::Int(sizeof(float), 1);
    const ShaderDataType ShaderDataType::Int2(sizeof(float), 2);
    const ShaderDataType ShaderDataType::Int3(sizeof(float), 3);
    const ShaderDataType ShaderDataType::Int4(sizeof(float), 4);
    const ShaderDataType ShaderDataType::Bool(sizeof(float), 1);
}