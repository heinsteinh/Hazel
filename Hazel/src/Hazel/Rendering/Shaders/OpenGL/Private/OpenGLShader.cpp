#include "OpenGLShader.h"

#include "glad/glad.h"

namespace Hazel
{
	OpenGLShader::OpenGLShader(int type, const std::string &source)
		: id(glCreateShader(type))
	{
		const char *data = source.c_str();
		glShaderSource(id, 1, &data, nullptr);
		glCompileShader(id);
	}

	OpenGLShader::OpenGLShader(OpenGLShader &&other) noexcept
		: id(std::exchange(other.id, 0))
	{
	}

	OpenGLShader::~OpenGLShader()
	{
		if (id)
		{
			glDeleteShader(id);
		}
	}

	bool OpenGLShader::IsCompiled() const
	{
		int result = 0;
		glGetShaderiv(id, GL_COMPILE_STATUS, &result);
		return result == GL_TRUE;
	}

	std::string OpenGLShader::GetInfoLog() const
	{
		int maxLength = 0;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &maxLength);
		std::string infoLog(maxLength, '\0');
		glGetShaderInfoLog(id, maxLength, &maxLength, infoLog.data());
		infoLog.resize(maxLength);
		return infoLog;
	}

	OpenGLShader &OpenGLShader::operator=(OpenGLShader &&other) noexcept
	{
		std::swap(id, other.id);
		return *this;
	}
}