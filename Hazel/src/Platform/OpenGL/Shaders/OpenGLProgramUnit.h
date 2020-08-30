#pragma once

#include "Hazel/Shaders/ShaderType.h"

namespace Hazel
{
	class OpenGLProgramUnit
	{
	private:
		uint32_t id = 0;

	public:
		OpenGLProgramUnit(ShaderType type, const std::string &source);
		OpenGLProgramUnit(const OpenGLProgramUnit &other) = delete;
		OpenGLProgramUnit(OpenGLProgramUnit &&other) noexcept;
		~OpenGLProgramUnit();

		OpenGLProgramUnit &operator=(const OpenGLProgramUnit &other) = delete;
		OpenGLProgramUnit &operator=(OpenGLProgramUnit &&other) noexcept;

		bool IsCompiled() const;
		std::string GetInfoLog() const;

		constexpr uint32_t GetId() const
		{
			return id;
		}
	};
}