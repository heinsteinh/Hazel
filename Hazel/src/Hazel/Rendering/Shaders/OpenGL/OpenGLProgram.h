#pragma once

#include "Private/OpenGLShaderModule.h"

namespace Hazel
{
	class OpenGLProgram
	{
	private:
		uint32_t id = 0;

	public:
		OpenGLProgram();
		~OpenGLProgram();

		void Attach(const OpenGLShaderModule &shader);
		void Detach(const OpenGLShaderModule &shader);
		void Link();
		bool IsLinked() const;
		std::string GetInfoLog() const;
		void Bind() const;
		void Unbind() const;

		uint32_t GetId() const
		{
			return id;
		}

		bool IsValid() const
		{
			return id != 0;
		}
	};
}