#include "OpenGLShader.h"

#include "glad/glad.h"

#include "OpenGLShaderCompiler.h"

namespace Hazel
{
	OpenGLShader::OpenGLShader(const ShaderInfo &info)
		: name(info.Name),
		holder(info)
	{
		Log::Info("Shader '{}' successfully created with id {}.", name, holder.GetId());
	}

	OpenGLShader::~OpenGLShader()
	{
		Log::Info("Shader '{}' (id: {}) destruction.", name, holder.GetId());
	}

	void OpenGLShader::Bind() const
	{
		holder.Bind();
	}

	void OpenGLShader::Unbind() const
	{
		holder.Unbind();
	}

	const std::string &OpenGLShader::GetName() const
	{
		return name;
	}

	void OpenGLShader::Set(const std::string &name, int value)
	{
		holder.Set(name, value);
	}

	void OpenGLShader::Set(const std::string &name, float value)
	{
		holder.Set(name, value);
	}

	void OpenGLShader::Set(const std::string &name, const glm::vec2 &value)
	{
		holder.Set(name, value);
	}

	void OpenGLShader::Set(const std::string &name, const glm::vec3 &value)
	{
		holder.Set(name, value);
	}

	void OpenGLShader::Set(const std::string &name, const glm::vec4 &value)
	{
		holder.Set(name, value);
	}

	void OpenGLShader::Set(const std::string &name, const glm::mat3 &value)
	{
		holder.Set(name, value);
	}

	void OpenGLShader::Set(const std::string &name, const glm::mat4 &value)
	{
		holder.Set(name, value);
	}

	void OpenGLShader::Set(const std::string &name, const int *values, size_t size)
	{
		holder.Set(name, values, size);
	}
}