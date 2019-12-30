#include "OpenGLShaderProgram.h"

#include "glad/glad.h"

namespace Hazel
{
    OpenGLShaderProgram::OpenGLShaderProgram()
    {
        id = glCreateProgram();
    }

    OpenGLShaderProgram::~OpenGLShaderProgram()
    {
        glDeleteProgram(id);
    }

    void OpenGLShaderProgram::Attach(const OpenGLCompiledShader &shader)
    {
        auto shaderId = shader.GetId();
        glAttachShader(id, shaderId);
        shaders.insert(shaderId);
    }

    void OpenGLShaderProgram::Detach(const OpenGLCompiledShader &shader)
    {
        auto shaderId = shader.GetId();
        if (shaders.find(shaderId) != shaders.end())
        {
            glDetachShader(id, shaderId);
        }
    }

    void OpenGLShaderProgram::Link()
    {
        glLinkProgram(id);
        CheckLinkStatus();
        CheckInfoLog();
        Cleanup();
    }

    void OpenGLShaderProgram::CheckLinkStatus()
    {
        int result = 0;
        glGetProgramiv(id, GL_LINK_STATUS, &result);
        linked = result == GL_TRUE;
    }

    void OpenGLShaderProgram::CheckInfoLog()
    {
        int maxLength = 0;
        glGetProgramiv(id, GL_INFO_LOG_LENGTH, &maxLength);
        std::vector<char> message((size_t)maxLength + 1);
        glGetProgramInfoLog(id, maxLength, &maxLength, message.data());
        infoLog = message.data();
    }

    void OpenGLShaderProgram::Cleanup()
    {
        for (auto shader : shaders)
        {
            glDetachShader(id, shader);
        }
        shaders.clear();
    }
}