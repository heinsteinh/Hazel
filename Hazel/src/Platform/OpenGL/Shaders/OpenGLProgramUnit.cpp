#include "OpenGLProgramUnit.h"

#include "glad/glad.h"

#include "OpenGLShaderType.h"

namespace Hazel
{
	OpenGLProgramUnit::OpenGLProgramUnit(ShaderType type, const std::string &source)
		: id(glCreateShader(OpenGLShaderType::FromShaderType(type)))
	{
		const char *data = source.c_str();
		glShaderSource(id, 1, &data, nullptr);
		glCompileShader(id);
	}

	OpenGLProgramUnit::OpenGLProgramUnit(OpenGLProgramUnit &&other) noexcept
		: id(std::exchange(other.id, 0))
	{
	}

	OpenGLProgramUnit::~OpenGLProgramUnit()
	{
		if (id)
		{
			glDeleteShader(id);
		}
	}

	OpenGLProgramUnit &OpenGLProgramUnit::operator=(OpenGLProgramUnit &&other) noexcept
	{
		std::swap(id, other.id);
		return *this;
	}

	bool OpenGLProgramUnit::IsCompiled() const
	{
		int result = 0;
		glGetShaderiv(id, GL_COMPILE_STATUS, &result);
		return result == GL_TRUE;
	}

	std::string OpenGLProgramUnit::GetInfoLog() const
	{
		int maxLength = 0;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &maxLength);
		std::string infoLog(maxLength, '\0');
		glGetShaderInfoLog(id, maxLength, &maxLength, infoLog.data());
		infoLog.resize(maxLength);
		return infoLog;
	}
}