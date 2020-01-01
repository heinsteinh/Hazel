#include "OpenGLDataType.h"

#include "glad/glad.h"

namespace Hazel
{
    static const std::unordered_map<const ShaderDataType *, unsigned int> shaderDataTypes = {
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

    unsigned int Hazel::OpenGLDataType::GetShaderDataType(const ShaderDataType &type)
    {
        auto keyValue = shaderDataTypes.find(&type);
        if (keyValue == shaderDataTypes.end())
        {
            CoreError("Unknown shader data type: {}", type.GetSize());
            return 0;
        }
        return keyValue->second;
    }

    static const std::unordered_map<std::string, unsigned int> shaderTypes = {
        {"vertex", GL_VERTEX_SHADER},
        {"fragment", GL_FRAGMENT_SHADER},
        {"pixel", GL_FRAGMENT_SHADER}
    };

    unsigned int OpenGLDataType::GetShaderType(const std::string &name)
    {
        auto keyValue = shaderTypes.find(name);
        if (keyValue == shaderTypes.end())
        {
            CoreError("Unknown shader type: {}", name);
            return 0;
        }
        return keyValue->second;
    }
}