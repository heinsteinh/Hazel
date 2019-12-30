#include "OpenGLShaderCompiler.h"

#include "glad/glad.h"

namespace Hazel
{
    OpenGLShaderCompiler::OpenGLShaderCompiler(const std::string &vertexSource, const std::string &fragmentSource)
        : vertexShader(GL_VERTEX_SHADER, vertexSource),
        fragmentShader(GL_FRAGMENT_SHADER, fragmentSource)
    {
        Init();
    }

    void OpenGLShaderCompiler::Init()
    {
        DisplayCompilationLog("Vertex", vertexShader);
        DisplayCompilationLog("Fragment", fragmentShader);
        if (vertexShader.IsCompiled() && fragmentShader.IsCompiled())
        {
            CreateProgram();
        }
    }

    void OpenGLShaderCompiler::DisplayCompilationLog(const std::string &name, const OpenGLCompiledShader &shader)
    {
        shader.IsCompiled()
            ? CoreInfo("{} Shader compilation succeeded.", name)
            : CoreError("{} Shader compilation failed.", name);
        CoreInfo("Info log: {}", shader.GetInfoLog());
    }

    void OpenGLShaderCompiler::CreateProgram()
    {
        program.Attach(vertexShader);
        program.Attach(fragmentShader);
        program.Link();
        DisplayLinkLog();
    }

    void OpenGLShaderCompiler::DisplayLinkLog()
    {
        program.IsLinked()
            ? CoreInfo("Shader program link succeeded.")
            : CoreError("Shader program link failed.");
        CoreInfo("Info log: {}", program.GetInfoLog());
    }
}