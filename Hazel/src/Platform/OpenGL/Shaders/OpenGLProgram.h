#pragma once

#include "OpenGLCompiledShader.h"

namespace Hazel
{
	class OpenGLProgram
	{
	private:
		uint32_t id = 0;

	public:
		OpenGLProgram() = default;
		OpenGLProgram(const std::vector<OpenGLCompiledShader> &shaders);
		OpenGLProgram(const OpenGLProgram &other) = delete;
		OpenGLProgram(OpenGLProgram &&other) noexcept;
		~OpenGLProgram();

		OpenGLProgram &operator=(const OpenGLProgram &other) = delete;
		OpenGLProgram &operator=(OpenGLProgram &&other) noexcept;

		bool IsLinked() const;
		std::string GetInfoLog() const;
		void Detach(const OpenGLCompiledShader &shader);

		constexpr uint32_t GetId() const
		{
			return id;
		}

		constexpr uint32_t Release()
		{
			auto temp = id;
			id = 0;
			return temp;
		}
	};
}