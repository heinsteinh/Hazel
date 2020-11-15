#pragma once

#include "Hazel/Shaders/Shader.h"
#include "Helpers/OpenGLShader.h"

namespace Hazel
{
	class OpenGLProgram : public Shader
	{
	private:
		std::string name;
		uint32_t id = 0;

	public:
		OpenGLProgram(const std::string &name);
		virtual ~OpenGLProgram();

		void Attach(const OpenGLShader &shader);
		void Detach(const OpenGLShader &shader);
		void Link();
		bool IsLinked() const;
		std::string GetInfoLog() const;
		void Bind() const;
		void Unbind() const;
		int GetUniformLocation(const std::string &name) const;

		virtual const std::string &GetName() const override;
		virtual void Set(const std::string &name, int value) override;
		virtual void Set(const std::string &name, float value) override;
		virtual void Set(const std::string &name, const glm::vec2 &value) override;
		virtual void Set(const std::string &name, const glm::vec3 &value) override;
		virtual void Set(const std::string &name, const glm::vec4 &value) override;
		virtual void Set(const std::string &name, const glm::mat3 &value) override;
		virtual void Set(const std::string &name, const glm::mat4 &value) override;
		virtual void Set(const std::string &name, const int *values, size_t size) override;

		constexpr uint32_t GetId() const
		{
			return id;
		}
	};
}