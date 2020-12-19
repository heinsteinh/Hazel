#pragma once

#include <array>

#include "Hazel/Rendering/Shaders/OpenGL/OpenGLProgram.h"

namespace Hazel
{
	class OpenGLShaders
	{
	private:
		std::array<OpenGLShader, static_cast<size_t>(ShaderType::Count)> shaders;

	public:
		void Attach(OpenGLProgram &program) const
		{
			for (const auto &shader : shaders)
			{
				if (shader.IsValid())
				{
					program.Attach(shader);
				}
			}
		}

		void Detach(OpenGLProgram &program) const
		{
			for (const auto &shader : shaders)
			{
				if (shader.IsValid())
				{
					program.Detach(shader);
				}
			}
		}

		constexpr const OpenGLShader &Get(ShaderType shaderType) const
		{
			return shaders[static_cast<size_t>(shaderType)];
		}

		constexpr OpenGLShader &Get(ShaderType shaderType)
		{
			return shaders[static_cast<size_t>(shaderType)];
		}

		constexpr const OpenGLShader &operator[](ShaderType shaderType) const
		{
			return Get(shaderType);
		}

		constexpr OpenGLShader &operator[](ShaderType shaderType)
		{
			return Get(shaderType);
		}

		auto begin() const
		{
			return shaders.begin();
		}

		auto begin()
		{
			return shaders.begin();
		}

		auto end() const
		{
			return shaders.end();
		}
	};
}