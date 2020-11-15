#include "OpenGLProgram.h"

#include "glad/glad.h"

namespace Hazel
{
	OpenGLProgram::OpenGLProgram(const std::string &name)
		: name(name),
		id(glCreateProgram())
	{
		Log::Debug("Shader '{}' created with id {}.", name, id);
	}

	OpenGLProgram::~OpenGLProgram()
	{
		glDeleteProgram(id);
		Log::Debug("Shader '{}' with id {} deleted.", name, id);
	}

	void OpenGLProgram::Attach(const OpenGLShader &shader)
	{
		glAttachShader(id, shader.GetId());
	}

	void OpenGLProgram::Detach(const OpenGLShader &shader)
	{
		glDetachShader(id, shader.GetId());
	}

	void OpenGLProgram::Link()
	{
		glLinkProgram(id);
	}

	bool OpenGLProgram::IsLinked() const
	{
		int result = 0;
		glGetProgramiv(id, GL_LINK_STATUS, &result);
		return result == GL_TRUE;
	}

	std::string OpenGLProgram::GetInfoLog() const
	{
		int maxLength = 0;
		glGetProgramiv(id, GL_INFO_LOG_LENGTH, &maxLength);
		std::string infoLog(maxLength, '\0');
		glGetProgramInfoLog(id, maxLength, &maxLength, infoLog.data());
		infoLog.resize(maxLength);
		return infoLog;
	}

	void OpenGLProgram::Bind() const
	{
		glUseProgram(id);
	}

	void OpenGLProgram::Unbind() const
	{
		glUseProgram(0);
	}

	int OpenGLProgram::GetUniformLocation(const std::string &name) const
	{
		return glGetUniformLocation(id, name.c_str());
	}

	const std::string &OpenGLProgram::GetName() const
	{
		return name;
	}

	void OpenGLProgram::Set(const std::string &name, int value)
	{
		glUniform1i(GetUniformLocation(name), value);
	}

	void OpenGLProgram::Set(const std::string &name, float value)
	{
		glUniform1f(GetUniformLocation(name), value);
	}

	void OpenGLProgram::Set(const std::string &name, const glm::vec2 &value)
	{
		glUniform2f(GetUniformLocation(name), value[0], value[1]);
	}

	void OpenGLProgram::Set(const std::string &name, const glm::vec3 &value)
	{
		glUniform3f(GetUniformLocation(name), value[0], value[1], value[2]);
	}

	void OpenGLProgram::Set(const std::string &name, const glm::vec4 &value)
	{
		glUniform4f(GetUniformLocation(name), value[0], value[1], value[2], value[3]);
	}

	void OpenGLProgram::Set(const std::string &name, const glm::mat3 &value)
	{
		glUniformMatrix3fv(GetUniformLocation(name), 1, GL_FALSE, glm::value_ptr(value));
	}

	void OpenGLProgram::Set(const std::string &name, const glm::mat4 &value)
	{
		glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, glm::value_ptr(value));
	}

	void OpenGLProgram::Set(const std::string &name, const int *values, size_t size)
	{
		glUniform1iv(GetUniformLocation(name), static_cast<int>(size), values);
	}
}