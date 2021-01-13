#pragma once

#include <array>

#include "Hazel/Rendering/Shaders/OpenGL/OpenGLProgram.h"

namespace Hazel
{
	class OpenGLShaders
	{
	private:
		std::array<OpenGLShader, 2> shaders;

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

		const OpenGLShader &GetVertexShader() const
		{
			return shaders[0];
		}

		void AddVertexShader(OpenGLShader &&shader)
		{
			shaders[0] = std::move(shader);
		}

		const OpenGLShader &GetPixelShader() const
		{
			return shaders[1];
		}

		void AddPixelShader(OpenGLShader &&shader)
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