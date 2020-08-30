#include "OpenGLProgram.h"

#include "glad/glad.h"

namespace Hazel
{
	OpenGLProgram::OpenGLProgram(const std::vector<OpenGLProgramUnit> &shaders)
		: id(glCreateProgram())
	{
		for (const auto &shader : shaders)
		{
			glAttachShader(id, shader.GetId());
		}
		glLinkProgram(id);
		if (IsLinked())
		{
			for (const auto &shader : shaders)
			{
				glDetachShader(id, shader.GetId());
			}
		}
	}

	OpenGLProgram::OpenGLProgram(OpenGLProgram &&other) noexcept
		: id(std::exchange(other.id, 0))
	{
	}

	OpenGLProgram::~OpenGLProgram()
	{
		if (id)
		{
			glDeleteProgram(id);
		}
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

	OpenGLProgram &OpenGLProgram::operator=(OpenGLProgram &&other) noexcept
	{
		std::swap(id, other.id);
		return *this;
	}
}