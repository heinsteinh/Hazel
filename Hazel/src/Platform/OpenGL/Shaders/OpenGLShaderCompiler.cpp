#include "OpenGLShaderCompiler.h"

#include "glad/glad.h"

namespace Hazel
{
    unsigned int OpenGLShaderCompiler::Compile(const std::unordered_map<ShaderType, std::string> &sources)
    {
        CreateProgram(sources);
        RetreiveLinkStatus();
        RetreiveInfoLog();
        Cleanup();
        DisplayInfoLog();
        return programId;
    }

    void OpenGLShaderCompiler::CreateProgram(const std::unordered_map<ShaderType, std::string> &sources)
    {
        programId = glCreateProgram();
        Attach(sources);
        glLinkProgram(programId);
    }

    void OpenGLShaderCompiler::Attach(const std::unordered_map<ShaderType, std::string> &sources)
    {
        shaders.reserve(sources.size());
        for (const auto &[type, source] : sources)
        {
            Attach(type, source);
        }
    }

    void OpenGLShaderCompiler::Attach(ShaderType type, const std::string &source)
    {
        auto &shader = shaders.emplace_back(type, source);
        shader.IsCompiled()
            ? glAttachShader(programId, shader.GetId())
            : shaders.pop_back();
    }

    void OpenGLShaderCompiler::RetreiveLinkStatus()
    {
        int result = 0;
        glGetProgramiv(programId, GL_LINK_STATUS, &result);
        linked = result == GL_TRUE;
    }

    void OpenGLShaderCompiler::RetreiveInfoLog()
    {
        int maxLength = 0;
        glGetProgramiv(programId, GL_INFO_LOG_LENGTH, &maxLength);
        infoLog.resize(maxLength);
        glGetProgramInfoLog(programId, maxLength, &maxLength, infoLog.data());
        infoLog.resize(maxLength);
    }

    void OpenGLShaderCompiler::DisplayInfoLog()
    {
        linked
            ? CoreInfo("Shader program linked (id = {}).", programId)
            : CoreError("Shader program link failed.");
        CoreInfo("Info log: {}", infoLog);
    }

    void OpenGLShaderCompiler::Cleanup()
    {
        linked ? DetachShaders() : DeleteProgram();
        shaders.clear();
    }

    void OpenGLShaderCompiler::DetachShaders()
    {
        for (const auto &shader : shaders)
        {
            glDetachShader(programId, shader.GetId());
        }
    }

    void OpenGLShaderCompiler::DeleteProgram()
    {
        glDeleteProgram(programId);
        programId = 0;
    }
}