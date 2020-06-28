#include "OpenGLCompiledShader.h"

#include "glad/glad.h"

#include "OpenGLShaderType.h"

namespace Hazel
{
	OpenGLCompiledShader::OpenGLCompiledShader(ShaderType type, const std::string &source)
		: id(glCreateShader(OpenGLShaderType::FromShaderType(type)))
	{
		const char *data = source.c_str();
		glShaderSource(id, 1, &data, nullptr);
		glCompileShader(id);
	}

	OpenGLCompiledShader::OpenGLCompiledShader(OpenGLCompiledShader &&other) noexcept
		: id(other.id)
	{
		other.id = 0;
	}

	OpenGLCompiledShader::~OpenGLCompiledShader()
	{
		if (id != 0)
		{
			glDeleteShader(id);
		}
	}

	OpenGLCompiledShader &OpenGLCompiledShader::operator=(OpenGLCompiledShader &&other) noexcept
	{
		std::swap(id, other.id);
		return *this;
	}

	bool OpenGLCompiledShader::IsCompiled() const
	{
		int result = 0;
		glGetShaderiv(id, GL_COMPILE_STATUS, &result);
		return result == GL_TRUE;
	}

	std::string OpenGLCompiledShader::GetInfoLog() const
	{
		int maxLength = 0;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &maxLength);
		std::string infoLog(maxLength, '\0');
		glGetShaderInfoLog(id, maxLength, &maxLength, infoLog.data());
		infoLog.resize(maxLength);
		return infoLog;
	}
}