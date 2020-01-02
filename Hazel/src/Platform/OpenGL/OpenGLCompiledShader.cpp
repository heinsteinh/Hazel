#include "OpenGLCompiledShader.h"

#include <unordered_map>

#include "glad/glad.h"

namespace Hazel
{
    static const std::unordered_map<unsigned int, std::string> names = {
        {GL_VERTEX_SHADER, "Vertex Shader"},
        {GL_FRAGMENT_SHADER, "Fragment Shader"}
    };

    OpenGLCompiledShader::OpenGLCompiledShader(unsigned int type, const std::string &source)
    {
        Init(type, source);
    }

    OpenGLCompiledShader::OpenGLCompiledShader(OpenGLCompiledShader &&other)
        : id(other.id),
        compiled(other.compiled),
        infoLog(std::move(other.infoLog))
    {
        other.id = 0;
    }

    OpenGLCompiledShader::~OpenGLCompiledShader()
    {
        glDeleteShader(id);
    }

    void OpenGLCompiledShader::Init(unsigned int type, const std::string &source)
    {
        Compile(type, source);
        RetrieveCompilationStatus();
        RetrieveInfoLog();
        DisplayInfoLog(type);
    }

    void OpenGLCompiledShader::Compile(unsigned int type, const std::string &source)
    {
        id = glCreateShader(type);
        const char *data = source.c_str();
        glShaderSource(id, 1, &data, nullptr);
        glCompileShader(id);
    }

    void OpenGLCompiledShader::RetrieveCompilationStatus()
    {
        int result = 0;
        glGetShaderiv(id, GL_COMPILE_STATUS, &result);
        compiled = result == GL_TRUE;
    }

    void OpenGLCompiledShader::RetrieveInfoLog()
    {
        int maxLength = 0;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &maxLength);
        infoLog.resize(maxLength);
        glGetShaderInfoLog(id, maxLength, &maxLength, infoLog.data());
        infoLog.resize(maxLength);
    }

    void OpenGLCompiledShader::DisplayInfoLog(unsigned int type)
    {
        const std::string &name = names.at(type);
        compiled
            ? CoreInfo("Compilation of {} succeeded.", name)
            : CoreError("Compilation of {} failed.", name);
        CoreInfo("Info log: {}", infoLog);
    }
}