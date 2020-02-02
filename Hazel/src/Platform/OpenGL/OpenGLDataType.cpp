#include "OpenGLDataType.h"

#include "glad/glad.h"

namespace Hazel
{
    static const std::unordered_map<DataType, unsigned int> shaderDataTypes = {
        {DataType::Float, GL_FLOAT},
        {DataType::Integer, GL_INT},
        {DataType::Bool, GL_BOOL}
    };

    unsigned int Hazel::OpenGLDataType::GetShaderDataType(ShaderDataType type)
    {
        auto keyValue = shaderDataTypes.find(type.GetComponentType());
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