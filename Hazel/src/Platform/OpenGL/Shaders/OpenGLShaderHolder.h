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
		OpenGLProgram *GetShader() const
		{
			return program;
		}

		void SetShader(Shader *shader)
		{
			OpenGLBinder::Bind(program, shader);
		}
	};
}