#pragma once

#include "Hazel/Rendering/Shaders/Shader.h"
#include "OpenGLProgram.h"
#include "OpenGLVertexArray.h"

namespace Hazel
{
	class OpenGLShader : public Shader
	{
	private:
		std::shared_ptr<OpenGLProgram> program;
		std::shared_ptr<OpenGLVertexArray> vertexArray;

	public:
		OpenGLShader(const ShaderInfo &info, const std::shared_ptr<OpenGLProgram> &program)
			: Shader(info),
			program(program),
			vertexArray(std::make_shared<OpenGLVertexArray>())
		{
		}

		const std::shared_ptr<OpenGLProgram> &GetProgram() const
		{
			return program;
		}

		const std::shared_ptr<OpenGLVertexArray> &GetVertexArray() const
		{
			return vertexArray;
		}
	};
}