#include "OpenGLShader.h"

#include <unordered_map>

#include "glad/glad.h"

#include "Hazel/Core/Logger.h"
#include "ShaderCompilation/OpenGLShaderCompiler.h"

namespace Hazel
{
    unsigned int OpenGLShader::GetInternalType(const ShaderDataType &type)
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
        auto keyValue = types.find(&type);
        if (keyValue == types.end())
        {
            CoreError("Unknown shader data type: {}", type.GetSize());
            return 0;
        }
        return keyValue->second;
    }

    OpenGLShader::OpenGLShader(const std::string &vertexSource, const std::string &fragmentSource)
    {
        Init(vertexSource, fragmentSource);
    }

    OpenGLShader::~OpenGLShader()
    {
        glDeleteProgram(rendererId);
    }

    bool OpenGLShader::IsBuilt() const
    {
        return built;
    }

    void OpenGLShader::Bind() const
    {
        glUseProgram(rendererId);
    }

    void OpenGLShader::UnBind() const
    {
        glUseProgram(0);
    }

    void OpenGLShader::Init(const std::string &vertexSource, const std::string &fragmentSource)
    {
        OpenGLShaderCompiler compiler;
        built = compiler.Compile(vertexSource, fragmentSource);
        rendererId = compiler.GetRendererId();
    }
}