#pragma once

#include "Hazel/Rendering/Shaders/ShaderType.h"

namespace Hazel
{
	class OpenGLCompiledShader
	{
	private:
		uint32_t id = 0;

	public:
		OpenGLCompiledShader() = default;
		OpenGLCompiledShader(ShaderType type, const std::string &source);
		OpenGLCompiledShader(const OpenGLCompiledShader &other) = delete;
		OpenGLCompiledShader(OpenGLCompiledShader &&other) noexcept;
		~OpenGLCompiledShader();

		OpenGLCompiledShader &operator=(const OpenGLCompiledShader &other) = delete;
		OpenGLCompiledShader &operator=(OpenGLCompiledShader &&other) noexcept;

		bool IsCompiled() const;
		std::string GetInfoLog() const;

		constexpr uint32_t GetId() const
		{
			return id;
		}
	};
}