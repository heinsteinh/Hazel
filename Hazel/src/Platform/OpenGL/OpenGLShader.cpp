#include "OpenGLShader.h"

#include "glad/glad.h"
#include "glm/gtc/type_ptr.hpp"

#include "OpenGLShaderCompiler.h"

namespace Hazel
{
    OpenGLShader::OpenGLShader(
        const std::string &name,
        const std::string &vertexSource,
        const std::string &fragmentSource)
        : name(name)
    {
        id = OpenGLShaderCompiler().Compile(vertexSource, fragmentSource);
    }

    OpenGLShader::OpenGLShader(
        const std::string &name,
        const std::string &filename)
        : name(name)
    {
        id = OpenGLShaderCompiler().Compile(filename);
    }

    OpenGLShader::~OpenGLShader()
    {
        glDeleteProgram(id);
    }

    void OpenGLShader::UploadUniformInt(const std::string &name, int value)
    {
        glUniform1i(GetUniformLocation(name), value);
    }

    void OpenGLShader::UploadUniformFloat(const std::string &name, float value)
    {
        glUniform1f(GetUniformLocation(name), value);
    }

    void OpenGLShader::UploadUniformFloat2(const std::string &name, const glm::vec2 &value)
    {
        glUniform2f(GetUniformLocation(name), value[0], value[1]);
    }

    void OpenGLShader::UploadUniformFloat3(const std::string &name, const glm::vec3 &value)
    {
        glUniform3f(GetUniformLocation(name), value[0], value[1], value[3]);
    }

    void OpenGLShader::UploadUniformFloat4(const std::string &name, const glm::vec4 &value)
    {
        glUniform4f(GetUniformLocation(name), value[0], value[1], value[2], value[3]);
    }

    void OpenGLShader::UploadUniformMat3(const std::string &name, const glm::mat3 &value)
    {
        glUniformMatrix3fv(GetUniformLocation(name), 1, GL_FALSE, glm::value_ptr(value));
    }

    void OpenGLShader::UploadUniformMat4(const std::string &name, const glm::mat4 &value)
    {
        glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, glm::value_ptr(value));
    }

    bool OpenGLShader::IsExecutable() const
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

    int OpenGLShader::GetUniformLocation(const std::string &name)
    {
        return glGetUniformLocation(id, name.c_str());
    }
}