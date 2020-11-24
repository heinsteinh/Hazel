#pragma once

#include "Platform/OpenGL/Shaders/OpenGLProgram.h"
#include "Platform/OpenGL/GraphicsContext/OpenGLBinder.h"

namespace Hazel
{
	class OpenGLShaderHolder
	{
	private:
		OpenGLProgram *program = nullptr;

	public:
		inline OpenGLProgram *GetShader() const
		{
			return program;
		}

		inline void SetShader(const std::shared_ptr<Shader> &shader)
		{
			OpenGLBinder::Bind(program, shader);
		}
	};
}