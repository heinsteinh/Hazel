#include "OpenGLCompiledShader.h"

#include <unordered_map>

#include "glad/glad.h"

#include "Platform/OpenGL/Utils/OpenGLConvert.h"

namespace Hazel
{
    OpenGLCompiledShader::OpenGLCompiledShader(ShaderType type, const std::string &source)
        : type(type)
    {
        Init(source);
    }

    OpenGLCompiledShader::OpenGLCompiledShader(OpenGLCompiledShader &&other)
        : id(other.id),
        type(other.type),
        compiled(other.compiled),
        infoLog(std::move(other.infoLog))
    {
        other.id = 0;
    }

    OpenGLCompiledShader::~OpenGLCompiledShader()
    {
        glDeleteShader(id);
    }

    OpenGLCompiledShader &OpenGLCompiledShader::operator=(OpenGLCompiledShader &&other)
    {
        id = other.id;
        type = other.type;
        compiled = other.compiled;
        infoLog = std::move(other.infoLog);
        other.id = 0;
        return *this;
    }

    void OpenGLCompiledShader::Init(const std::string &source)
    {
        Compile(source);
        RetrieveCompilationStatus();
        RetrieveInfoLog();
        DisplayInfoLog();
    }

    void OpenGLCompiledShader::Compile(const std::string &source)
    {
        id = glCreateShader(OpenGLConvert::ToInternal(type));
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

    void OpenGLCompiledShader::DisplayInfoLog()
    {
        compiled
            ? CoreInfo("Compilation of {} shader succeeded (id = {}).", type.GetKey(), id)
            : CoreError("Compilation of {} shader failed.", type.GetKey());
        CoreInfo("Info log: {}", infoLog);
    }
}