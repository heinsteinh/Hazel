#include "OpenGLProgramData.h"

#include <vector>

#include "glad/glad.h"

namespace Hazel
{
    OpenGLProgramData::OpenGLProgramData()
    {
    }

    bool OpenGLProgramData::Link(const OpenGLShaderData &vertexData, const OpenGLShaderData &fragmentData)
    {
        CreateAndLink(vertexData, fragmentData);
        GetLinkResult(vertexData, fragmentData);
        Cleanup(vertexData, fragmentData);
        return linked;
    }

    unsigned int OpenGLProgramData::GetId() const
    {
        return id;
    }

    bool OpenGLProgramData::IsLinked() const
    {
        return linked;
    }

    const std::string &OpenGLProgramData::GetInfoLog() const
    {
        return infoLog;
    }

    void OpenGLProgramData::CreateAndLink(const OpenGLShaderData &vertexData, const OpenGLShaderData &fragmentData)
    {
        id = glCreateProgram();
        glAttachShader(id, vertexData.GetId());
        glAttachShader(id, fragmentData.GetId());
        glLinkProgram(id);
    }

    void OpenGLProgramData::GetLinkResult(const OpenGLShaderData &vertexData, const OpenGLShaderData &fragmentData)
    {
        int result = 0;
        glGetProgramiv(id, GL_LINK_STATUS, &result);
        linked = result == GL_TRUE;
        int maxLength = 0;
        glGetProgramiv(id, GL_INFO_LOG_LENGTH, &maxLength);
        std::vector<char> data(maxLength + 1);
        glGetProgramInfoLog(id, maxLength, &maxLength, data.data());
        infoLog = data.data();
    }

    void OpenGLProgramData::Cleanup(const OpenGLShaderData &vertexData, const OpenGLShaderData &fragmentData)
    {
        if (linked)
        {
            glDetachShader(id, vertexData.GetId());
            glDetachShader(id, fragmentData.GetId());
        }
        else
        {
            glDeleteProgram(id);
        }
    }
}