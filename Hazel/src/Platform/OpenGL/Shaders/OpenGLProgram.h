#pragma once

#include "OpenGLProgramUnit.h"

namespace Hazel
{
	class OpenGLProgram
	{
	private:
		uint32_t id = 0;

	public:
		OpenGLProgram(const std::vector<OpenGLProgramUnit> &shaders);
		OpenGLProgram(const OpenGLProgram &other) = delete;
		OpenGLProgram(OpenGLProgram &&other) noexcept;
		~OpenGLProgram();

		bool IsLinked() const;
		std::string GetInfoLog() const;

		OpenGLProgram &operator=(const OpenGLProgram &other) = delete;
		OpenGLProgram &operator=(OpenGLProgram &&other) noexcept;

		constexpr uint32_t GetId() const
		{
			return id;
		}
	};
}