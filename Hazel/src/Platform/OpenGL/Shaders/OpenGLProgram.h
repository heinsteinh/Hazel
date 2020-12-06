#pragma once

#include "Hazel/Shaders/Shader.h"
#include "Private/OpenGLShader.h"

namespace Hazel
{
	class OpenGLProgram : public Shader
	{
	private:
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

		constexpr uint32_t GetId() const
		{
			return id;
		}
	};
}