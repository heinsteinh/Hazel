#pragma once

#include "Hazel/Rendering/Shaders/Shader.h"
#include "Hazel/Rendering/Shaders/ShaderInfo.h"
#include "OpenGLProgram.h"

namespace Hazel
{
	class OpenGLShader : public Shader
	{
	private:
		std::string name;
		OpenGLProgram program;

	public:
		OpenGLShader(const ShaderInfo &info);
		virtual ~OpenGLShader();

		virtual void Bind() const override;
		virtual void Unbind() const override;
		virtual const std::string &GetName() const override;
		virtual void Set(const std::string &name, int value) override;
		virtual void Set(const std::string &name, float value) override;
		virtual void Set(const std::string &name, const glm::vec2 &value) override;
		virtual void Set(const std::string &name, const glm::vec3 &value) override;
		virtual void Set(const std::string &name, const glm::vec4 &value) override;
		virtual void Set(const std::string &name, const glm::mat3 &value) override;
		virtual void Set(const std::string &name, const glm::mat4 &value) override;
		virtual void Set(const std::string &name, const int *values, size_t size) override;

	private:
		int GetUniformLocation(const std::string &name);
	};
}