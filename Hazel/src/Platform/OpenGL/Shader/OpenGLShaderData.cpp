#include "OpenGLShaderData.h"

#include <vector>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace Hazel
{
    OpenGLShaderData::OpenGLShaderData(unsigned int type)
        : type(type)
    {
    }

    OpenGLShaderData::~OpenGLShaderData()
    {
        glDeleteShader(id);
    }

    bool OpenGLShaderData::Compile(const std::string &source)
    {
        CompileSource(source);
        GetCompilationResult();
        return compiled;
    }

    unsigned int OpenGLShaderData::GetId() const
    {
        return id;
    }

    bool OpenGLShaderData::IsCompiled() const
    {
        return compiled;
    }

    const std::string &OpenGLShaderData::GetInfoLog() const
    {
        return infoLog;
    }

    void OpenGLShaderData::CompileSource(const std::string &source)
    {
        id = glCreateShader(type);
        const char *data = source.c_str();
        glShaderSource(id, 1, &data, 0);
        glCompileShader(id);
    }

    void OpenGLShaderData::GetCompilationResult()
    {
        int result = 0;
        glGetShaderiv(id, GL_COMPILE_STATUS, &result);
        compiled = result == GL_TRUE;
        int maxLength = 0;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &maxLength);
        std::vector<char> data(maxLength + 1);
        glGetShaderInfoLog(id, maxLength, &maxLength, data.data());
        infoLog = data.data();
    }
}