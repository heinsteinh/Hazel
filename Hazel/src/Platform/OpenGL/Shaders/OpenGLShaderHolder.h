#pragma once

#include "Platform/OpenGL/Shaders/OpenGLProgram.h"

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
			if (shader && program != shader.get())
			{
				HZ_ASSERT(typeid(*shader) == typeid(OpenGLProgram), "Not an OpenGL type.");
				program = static_cast<OpenGLProgram *>(shader.get());
				program->Bind();
			}
		}
	};
}