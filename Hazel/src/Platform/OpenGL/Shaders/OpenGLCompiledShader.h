#pragma once

#include "Hazel/Rendering/Shaders/ShaderType.h"

namespace Hazel
{
	class OpenGLCompiledShader
	{
	private:
		unsigned int id = 0;

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

		constexpr unsigned int GetId() const
		{
			return id;
		}

		constexpr unsigned int Release()
		{
			auto temp = id;
			id = 0;
			return temp;
		}
	};
}