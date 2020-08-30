#include "OpenGLShaderHolder.h"

#include "glad/glad.h"

#include "OpenGLShaderCompiler.h"

namespace Hazel
{
	OpenGLShaderHolder::OpenGLShaderHolder(const ShaderInfo &info)
		: program(OpenGLShaderCompiler::CompileAndLink(info))
	{
	}

	void OpenGLShaderHolder::Bind() const
	{
		glUseProgram(program.GetId());
	}

	void OpenGLShaderHolder::Unbind() const
	{
		glUseProgram(0);
	}

	int OpenGLShaderHolder::GetUniformLocation(const std::string &name) const
	{
		return glGetUniformLocation(program.GetId(), name.c_str());
	}

	void OpenGLShaderHolder::Set(const std::string &name, int value)
	{
		glUniform1i(GetUniformLocation(name), value);
	}

	void OpenGLShaderHolder::Set(const std::string &name, float value)
	{
		glUniform1f(GetUniformLocation(name), value);
	}

	void OpenGLShaderHolder::Set(const std::string &name, const glm::vec2 &value)
	{
		glUniform2f(GetUniformLocation(name), value[0], value[1]);
	}

	void OpenGLShaderHolder::Set(const std::string &name, const glm::vec3 &value)
	{
		glUniform3f(GetUniformLocation(name), value[0], value[1], value[2]);
	}

	void OpenGLShaderHolder::Set(const std::string &name, const glm::vec4 &value)
	{
		glUniform4f(GetUniformLocation(name), value[0], value[1], value[2], value[3]);
	}

	void OpenGLShaderHolder::Set(const std::string &name, const glm::mat3 &value)
	{
		glUniformMatrix3fv(GetUniformLocation(name), 1, GL_FALSE, glm::value_ptr(value));
	}

	void OpenGLShaderHolder::Set(const std::string &name, const glm::mat4 &value)
	{
		glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, glm::value_ptr(value));
	}

	void OpenGLShaderHolder::Set(const std::string &name, const int *values, size_t size)
	{
		glUniform1iv(GetUniformLocation(name), static_cast<int>(size), values);
	}
}