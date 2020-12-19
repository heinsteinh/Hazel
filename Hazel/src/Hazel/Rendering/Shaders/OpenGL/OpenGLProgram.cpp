#include "OpenGLProgram.h"

#include "glad/glad.h"

#include "Hazel/Core/Logging/Log.h"

namespace Hazel
{
	OpenGLProgram::OpenGLProgram(const std::string &name)
		: Shader(name),
		id(glCreateProgram())
	{
		Log::Debug("Shader '{}' created with id {}.", name, id);
	}

	OpenGLProgram::~OpenGLProgram()
	{
		glDeleteProgram(id);
		Log::Debug("Shader '{}' with id {} deleted.", GetName(), id);
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
}