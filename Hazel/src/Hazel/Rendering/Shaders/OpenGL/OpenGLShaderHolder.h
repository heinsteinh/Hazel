#pragma once

#include "Hazel/Rendering/Shaders/OpenGL/OpenGLProgram.h"
#include "Hazel/Rendering/GraphicsContext/OpenGL/OpenGLBinder.h"

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