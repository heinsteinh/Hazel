#include "OpenGLShaderLinker.h"

#include "glad/glad.h"

namespace Hazel
{
    unsigned int OpenGLShaderLinker::CreateProgram(const std::unordered_map<unsigned int, std::string> &sources)
    {
        AttachAndLink(sources);
        RetreiveLinkStatus();
        RetreiveInfoLog();
        Cleanup();
        DisplayInfoLog();
        return programId;
    }

    void OpenGLShaderLinker::AttachAndLink(const std::unordered_map<unsigned int, std::string> &sources)
    {
        programId = glCreateProgram();
        for (const auto &[type, source] : sources)
        {
            Attach(type, source);
        }
        glLinkProgram(programId);
    }

    void OpenGLShaderLinker::Attach(unsigned int type, const std::string &source)
    {
        auto &shader = shaders.emplace_back(type, source);
        if (shader.IsCompiled())
        {
            glAttachShader(programId, shader.GetId());
        }
        else
        {
            shaders.pop_back();
        }
    }

    void OpenGLShaderLinker::RetreiveLinkStatus()
    {
        int result = 0;
        glGetProgramiv(programId, GL_LINK_STATUS, &result);
        linked = result == GL_TRUE;
    }

    void OpenGLShaderLinker::RetreiveInfoLog()
    {
        int maxLength = 0;
        glGetProgramiv(programId, GL_INFO_LOG_LENGTH, &maxLength);
        infoLog.resize(maxLength);
        glGetProgramInfoLog(programId, maxLength, &maxLength, infoLog.data());
        infoLog.resize(maxLength);
    }

    void OpenGLShaderLinker::DisplayInfoLog()
    {
        linked
            ? CoreInfo("Shader program link succeeded.")
            : CoreError("Shader program link failed.");
        CoreInfo("Info log: {}", infoLog);
    }

    void OpenGLShaderLinker::Cleanup()
    {
        if (linked)
        {
            for (const auto &shader : shaders)
            {
                glDetachShader(programId, shader.GetId());
            }
        }
        else
        {
            glDeleteProgram(programId);
            programId = 0;
        }
        shaders.clear();
    }
}