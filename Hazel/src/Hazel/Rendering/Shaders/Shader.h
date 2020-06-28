#pragma once

namespace Hazel
{
	class Shader
	{
	public:
		virtual ~Shader() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;
		virtual const std::string &GetName() const = 0;
		virtual void Set(const std::string &name, int value) = 0;
		virtual void Set(const std::string &name, float value) = 0;
		virtual void Set(const std::string &name, const glm::vec2 &value) = 0;
		virtual void Set(const std::string &name, const glm::vec3 &value) = 0;
		virtual void Set(const std::string &name, const glm::vec4 &value) = 0;
		virtual void Set(const std::string &name, const glm::mat3 &value) = 0;
		virtual void Set(const std::string &name, const glm::mat4 &value) = 0;
		virtual void Set(const std::string &name, const int *values, size_t size) = 0;
	};
}