#include "OpenGLShaderModule.h"

#include "glad/glad.h"

namespace Hazel
{
	OpenGLShaderModule::OpenGLShaderModule(int type, const std::string &source)
		: id(glCreateShader(type))
	{
		const char *data = source.c_str();
		glShaderSource(id, 1, &data, nullptr);
		glCompileShader(id);
	}

	OpenGLShaderModule::OpenGLShaderModule(OpenGLShaderModule &&other) noexcept
		: id(std::exchange(other.id, 0))
	{
	}

	OpenGLShaderModule::~OpenGLShaderModule()
	{
		if (id)
		{
			glDeleteShader(id);
		}
	}

	bool OpenGLShaderModule::IsCompiled() const
	{
		int result = 0;
		glGetShaderiv(id, GL_COMPILE_STATUS, &result);
		return result == GL_TRUE;
	}

	std::string OpenGLShaderModule::GetInfoLog() const
	{
		int maxLength = 0;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &maxLength);
		std::string infoLog(maxLength, '\0');
		glGetShaderInfoLog(id, maxLength, &maxLength, infoLog.data());
		infoLog.resize(maxLength);
		return infoLog;
	}

	OpenGLShaderModule &OpenGLShaderModule::operator=(OpenGLShaderModule &&other) noexcept
	{
		std::swap(id, other.id);
		return *this;
	}
}