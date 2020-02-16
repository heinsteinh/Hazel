#include "OpenGLShader.h"

#include "glad/glad.h"
#include "glm/gtc/type_ptr.hpp"

#include "OpenGLShaderCompiler.h"

namespace Hazel
{
    OpenGLShader::OpenGLShader(const ShaderInfo &info)
        : name(info.GetName())
    {
        id = OpenGLShaderCompiler().Compile(info.GetSources());
    }

    OpenGLShader::~OpenGLShader()
    {
        glDeleteProgram(id);
    }

    bool OpenGLShader::IsCompiled() const
    {
        return id != 0;
    }

    const std::string &OpenGLShader::GetName() const
    {
        return name;
    }

    void OpenGLShader::Bind() const
    {
        glUseProgram(id);
    }

    void OpenGLShader::UnBind() const
    {
        glUseProgram(0);
    }

    void OpenGLShader::Set(const std::string &name, int value)
    {
        glUniform1i(GetUniformLocation(name), value);
    }

    void OpenGLShader::Set(const std::string &name, float value)
    {
        glUniform1f(GetUniformLocation(name), value);
    }

    void OpenGLShader::Set(const std::string &name, const glm::vec2 &value)
    {
        glUniform2f(GetUniformLocation(name), value[0], value[1]);
    }

    void OpenGLShader::Set(const std::string &name, const glm::vec3 &value)
    {
        glUniform3f(GetUniformLocation(name), value[0], value[1], value[2]);
    }

    void OpenGLShader::Set(const std::string &name, const glm::vec4 &value)
    {
        glUniform4f(GetUniformLocation(name), value[0], value[1], value[2], value[3]);
    }

    void OpenGLShader::Set(const std::string &name, const glm::mat3 &value)
    {
        glUniformMatrix3fv(GetUniformLocation(name), 1, GL_FALSE, glm::value_ptr(value));
    }

    void OpenGLShader::Set(const std::string &name, const glm::mat4 &value)
    {
        glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, glm::value_ptr(value));
    }

    int OpenGLShader::GetUniformLocation(const std::string &name)
    {
        return glGetUniformLocation(id, name.c_str());
    }
}