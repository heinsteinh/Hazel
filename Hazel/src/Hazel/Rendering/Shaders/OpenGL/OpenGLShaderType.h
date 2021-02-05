#pragma once

#include "glad/glad.h"

#include "Hazel/Rendering/Shaders/ShaderType.h"
#include "Hazel/Rendering/Shaders/ShaderCompilationException.h"

namespace Hazel
{
	class OpenGLShaderType
	{
	public:
		static GLenum GetShaderType(ShaderType shaderType)
		{
			switch (shaderType)
			{
			case ShaderType::Vertex:
				return GL_VERTEX_SHADER;
			case ShaderType::Fragment:
				return GL_FRAGMENT_SHADER;
			}
			throw ShaderCompilationException("Invalid shader type");
		}
	};
}