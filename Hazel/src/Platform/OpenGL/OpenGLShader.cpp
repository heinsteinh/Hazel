#include "OpenGLShader.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "Hazel/Core/Logger.h"
#include "Shader/OpenGLShaderCompiler.h"

namespace Hazel
{
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