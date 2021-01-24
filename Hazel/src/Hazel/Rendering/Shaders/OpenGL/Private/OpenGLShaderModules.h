#pragma once

#include <array>

#include "OpenGLProgram.h"

namespace Hazel
{
	class OpenGLShaderModules
	{
	private:
		std::array<OpenGLShaderModule, 2> shaders;

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

		const OpenGLShaderModule &GetVertexShader() const
		{
			return shaders[0];
		}

		void AddVertexShader(OpenGLShaderModule &&shader)
		{
			shaders[0] = std::move(shader);
		}

		const OpenGLShaderModule &GetPixelShader() const
		{
			return shaders[1];
		}

		void AddPixelShader(OpenGLShaderModule &&shader)
		{
			shaders[1] = std::move(shader);
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