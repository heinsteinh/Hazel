#include "OpenGLShaderLinker.h"

#include "glad/glad.h"

namespace Hazel
{
    void OpenGLShaderLinker::Attach(const OpenGLCompiledShader &shader)
    {
        shaders.insert(shader.GetId());
    }

    void OpenGLShaderLinker::Detach(const OpenGLCompiledShader &shader)
    {
        auto i = shaders.find(shader.GetId());
        if (i != shaders.end())
        {
            shaders.erase(i);
        }
    }

    unsigned int OpenGLShaderLinker::CreateProgram()
    {
        AttachAndLink();
        RetreiveLinkStatus();
        RetreiveInfoLog();
        Cleanup();
        DisplayInfoLog();
        return programId;
    }

    void OpenGLShaderLinker::AttachAndLink()
    {
        programId = glCreateProgram();
        for (auto shader : shaders)
        {
            glAttachShader(programId, shader);
        }
        glLinkProgram(programId);
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
            for (auto shader : shaders)
            {
                glDetachShader(programId, shader);
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