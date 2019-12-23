#include "OpenGLShader.h"

#include <unordered_map>

#include "glad/glad.h"

#include "Hazel/Core/Logger.h"

namespace Hazel
{
    OpenGLShader::OpenGLShader(const std::string &vertexSource, const std::string &fragmentSource)
        : vertexShader(GL_VERTEX_SHADER, vertexSource),
        fragmentShader(GL_FRAGMENT_SHADER, fragmentSource)
    {
        Init();
    }

    OpenGLShader::~OpenGLShader()
    {
    }

    bool OpenGLShader::IsExecutable() const
    {
        return program.IsLinked();
    }

    void OpenGLShader::Bind() const
    {
        glUseProgram(program.GetId());
    }

    void OpenGLShader::UnBind() const
    {
        glUseProgram(0);
    }

    void OpenGLShader::Init()
    {
        DisplayCompilationLog("Vertex", vertexShader);
        DisplayCompilationLog("Fragment", fragmentShader);
        if (vertexShader.IsCompiled() && fragmentShader.IsCompiled())
        {
            CreateProgram();
        }
    }

    void OpenGLShader::DisplayCompilationLog(const std::string &name, const OpenGLCompiledShader &shader)
    {
        shader.IsCompiled()
            ? CoreInfo("Shader {} compilation succeeded.", name)
            : CoreError("Shader {} compilation failed.", name);
        CoreInfo("Info log: {}", shader.GetInfoLog());
    }

    void OpenGLShader::CreateProgram()
    {
        program.Attach(vertexShader);
        program.Attach(fragmentShader);
        program.Link();
        DisplayLinkLog();
    }

    void OpenGLShader::DisplayLinkLog()
    {
        program.IsLinked()
            ? CoreInfo("Shader program link succeeded.")
            : CoreError("Shader program link failed.");
        CoreInfo("Info log: {}", program.GetInfoLog());
    }
}