#pragma once

#include "Hazel/Rendering/Shaders/ShaderInfo.h"
#include "Hazel/Rendering/Shaders/ShaderCompilationException.h"
#include "OpenGLCompiledShader.h"
#include "OpenGLProgram.h"

namespace Hazel
{
	class OpenGLShaderBuilder
	{
	public:
		static inline OpenGLProgram Build(const ShaderInfo &info)
		{
			std::vector<OpenGLCompiledShader> shaders;
			shaders.reserve(info.Sources.size());
			for (const auto &[type, source] : info.Sources)
			{
				shaders.push_back(Compile(type, source));
			}
			return Link(shaders);
		}

		static inline OpenGLCompiledShader Compile(ShaderType type, const std::string &source)
		{
			OpenGLCompiledShader shader(type, source);
			if (!shader.IsCompiled())
			{
				throw ShaderCompilationException(type, shader.GetInfoLog());
			}
			return shader;
		}

		static inline OpenGLProgram Link(const std::vector<OpenGLCompiledShader> &shaders)
		{
			OpenGLProgram program(shaders);
			if (!program.IsLinked())
			{
				throw ShaderCompilationException("Shader link failed: " + program.GetInfoLog());
			}
			for (const auto &shader : shaders)
			{
				program.Detach(shader);
			}
			return program;
		}

		OpenGLShaderBuilder() = delete;
	};
}