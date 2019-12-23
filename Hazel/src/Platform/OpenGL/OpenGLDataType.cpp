#include "OpenGLDataType.h"

#include <unordered_map>

#include "glad/glad.h"

#include "Hazel/Core/Logger.h"

namespace Hazel
{
    static const std::unordered_map<const ShaderDataType *, unsigned int> types = {
        {&ShaderDataType::Float, GL_FLOAT},
        {&ShaderDataType::Float2, GL_FLOAT},
        {&ShaderDataType::Float3, GL_FLOAT},
        {&ShaderDataType::Float4, GL_FLOAT},
        {&ShaderDataType::Matrix3, GL_FLOAT},
        {&ShaderDataType::Matrix4, GL_FLOAT},
        {&ShaderDataType::Int, GL_INT},
        {&ShaderDataType::Int2, GL_INT},
        {&ShaderDataType::Int3, GL_INT},
        {&ShaderDataType::Int4, GL_INT},
        {&ShaderDataType::Bool, GL_BOOL}
    };

    unsigned int Hazel::OpenGLDataType::GetInternalType(const ShaderDataType &type)
    {
        auto keyValue = types.find(&type);
        if (keyValue == types.end())
        {
            CoreError("Unknown shader data type: {}", type.GetSize());
            return 0;
        }
        return keyValue->second;
    }
}