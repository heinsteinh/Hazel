#pragma once

#include "Hazel/Shaders/ShaderInfo.h"
#include "OpenGLProgram.h"

namespace Hazel
{
	class OpenGLShaderHolder
	{
	private:
		OpenGLProgram program;

	public:
		OpenGLShaderHolder(const ShaderInfo &info);

		void Bind() const;
		void Unbind() const;
		int GetUniformLocation(const std::string &name) const;
		void Set(const std::string &name, int value);
		void Set(const std::string &name, float value);
		void Set(const std::string &name, const glm::vec2 &value);
		void Set(const std::string &name, const glm::vec3 &value);
		void Set(const std::string &name, const glm::vec4 &value);
		void Set(const std::string &name, const glm::mat3 &value);
		void Set(const std::string &name, const glm::mat4 &value);
		void Set(const std::string &name, const int *values, size_t size);

		constexpr uint32_t GetId() const
		{
			return program.GetId();
		}
	};
}