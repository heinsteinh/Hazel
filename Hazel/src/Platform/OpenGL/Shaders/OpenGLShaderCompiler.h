#pragma once

#include "Hazel/Shaders/ShaderInfo.h"
#include "Hazel/Shaders/ShaderCompilationException.h"
#include "OpenGLProgramUnit.h"
#include "OpenGLProgram.h"

namespace Hazel
{
	class OpenGLShaderCompiler
	{
	public:
		static inline OpenGLProgram CompileAndLink(const ShaderInfo &info)
		{
			std::vector<OpenGLProgramUnit> shaders;
			shaders.reserve(info.Sources.size());
			for (const auto &[type, source] : info.Sources)
			{
				shaders.push_back(Compile(type, source));
			}
			return Link(shaders);
		}

	private:
		static inline OpenGLProgramUnit Compile(ShaderType type, const std::string &source)
		{
			OpenGLProgramUnit shader(type, source);
			if (!shader.IsCompiled())
			{
				throw ShaderCompilationException(type, shader.GetInfoLog());
			}
			return shader;
		}

		static inline OpenGLProgram Link(const std::vector<OpenGLProgramUnit> &shaders)
		{
			OpenGLProgram program(shaders);
			if (!program.IsLinked())
			{
				throw ShaderCompilationException(fmt::format("Shader link failed: {}", program.GetInfoLog()));
			}
			return program;
		}

		OpenGLShaderCompiler() = delete;
	};
}