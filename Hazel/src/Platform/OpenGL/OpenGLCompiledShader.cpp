#include "OpenGLCompiledShader.h"

#include "glad/glad.h"

#include "Hazel/Core/Logger.h"

namespace Hazel
{
    OpenGLCompiledShader::OpenGLCompiledShader(unsigned int type, const std::string &source)
    {
        Init(type, source);
    }

    OpenGLCompiledShader::~OpenGLCompiledShader()
    {
        glDeleteShader(id);
    }

    unsigned int OpenGLCompiledShader::GetId() const
    {
        return id;
    }

    bool OpenGLCompiledShader::IsCompiled() const
    {
        return compiled;
    }

    const std::string &OpenGLCompiledShader::GetInfoLog() const
    {
        return infoLog;
    }

    void OpenGLCompiledShader::Init(unsigned int type, const std::string &source)
    {
        Compile(type, source);
        CheckCompilationStatus();
        CheckInfoLog();
    }

    void OpenGLCompiledShader::Compile(unsigned int type, const std::string &source)
    {
        id = glCreateShader(type);
        const char *data = source.c_str();
        glShaderSource(id, 1, &data, nullptr);
        glCompileShader(id);
    }

    void OpenGLCompiledShader::CheckCompilationStatus()
    {
        int result = 0;
        glGetShaderiv(id, GL_COMPILE_STATUS, &result);
        compiled = result == GL_TRUE;
    }

    void OpenGLCompiledShader::CheckInfoLog()
    {
        int maxLength = 0;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &maxLength);
        std::vector<char> message((size_t)maxLength + 1);
        glGetShaderInfoLog(id, maxLength, &maxLength, message.data());
        infoLog = message.data();
    }
}