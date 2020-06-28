#pragma once

#include "glad/glad.h"

#include "Hazel/Rendering/Shaders/ShaderType.h"

namespace Hazel
{
	class OpenGLShaderType
	{
	public:
		static constexpr unsigned int FromShaderType(ShaderType type)
		{
			switch (type)
			{
			case ShaderType::Vertex:
				return GL_VERTEX_SHADER;
			case ShaderType::Pixel:
				return GL_FRAGMENT_SHADER;
			}
			return 0;
		}

		OpenGLShaderType() = delete;
	};
}