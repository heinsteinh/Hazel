#include "OpenGLShaderCompiler.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "Hazel/Core/Logger.h"

namespace Hazel
{
    OpenGLShaderCompiler::OpenGLShaderCompiler()
        : vertexData(GL_VERTEX_SHADER),
        fragmentData(GL_FRAGMENT_SHADER)
    {
    }

    bool OpenGLShaderCompiler::Compile(const std::string &vertexSource, const std::string &fragmentSource)
    {
        return CompileSource(vertexSource, fragmentSource) && CreateProgramAndLink();
    }

    unsigned int OpenGLShaderCompiler::GetRendererId() const
    {
        return rendererId;
    }

    bool OpenGLShaderCompiler::CompileSource(const std::string &vertexSource, const std::string &fragmentSource)
    {
        bool compiled = vertexData.Compile(vertexSource) && fragmentData.Compile(fragmentSource);
        DisplayShaderCompilationLog();
        return compiled;
    }

    void OpenGLShaderCompiler::DisplayShaderCompilationLog()
    {
        if (!vertexData.IsCompiled())
        {
            CoreError("Vertex shader compilation failed.");
        }
        else if (!fragmentData.IsCompiled())
        {
            CoreError("Fragment shader compilation failed.");
        }
        else
        {
            CoreInfo("Shaders compilation success.");
        }
        CoreInfo("Vertex shader info log: {}.", vertexData.GetInfoLog());
        CoreInfo("Fragment shader info log: {}.", fragmentData.GetInfoLog());
    }

    bool OpenGLShaderCompiler::CreateProgramAndLink()
    {
        bool linked = program.Link(vertexData, fragmentData);
        DisplayProgramLinkLog();
        rendererId = linked ? program.GetId() : 0;
        return linked;
    }

    void OpenGLShaderCompiler::DisplayProgramLinkLog()
    {
        if (!program.IsLinked())
        {
            CoreError("Shader program link failed.");
        }
        else
        {
            CoreInfo("Shader program link success.");
        }
        CoreInfo("Shader program link info log: {}", program.GetInfoLog());
    }
}