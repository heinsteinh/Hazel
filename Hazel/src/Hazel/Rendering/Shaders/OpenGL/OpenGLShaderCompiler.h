#pragma once

#include <vector>
#include <memory>

#include "OpenGLProgram.h"
#include "Private/OpenGLShaders.h"

namespace Hazel
{
	class OpenGLShaderCompiler
	{
	public:
		static std::shared_ptr<OpenGLProgram> Compile(const ShaderInfo &info)
		{
			if (!info.Sources.IsValid())
			{
				throw ShaderCompilationException("Shader must at least contain vertex and pixel sources.");
			}
			return Link(info.Name, CompileShaders(info.Sources));
		}

	private:
		static OpenGLShaders CompileShaders(const ShaderSourceMap &sources)
		{
			OpenGLShaders shaders;
			for (const auto &[shaderType, source] : sources)
			{
				if (!source.empty())
				{
					shaders[shaderType] = CompileShader(shaderType, source);
				}
			}
			return shaders;
		}

		static OpenGLShader CompileShader(ShaderType shaderType, const std::string &source)
		{
			OpenGLShader shader(shaderType, source);
			if (!shader.IsCompiled())
			{
				throw ShaderCompilationException(fmt::format("Shader {} compilation failed: {}", shaderType, shader.GetInfoLog()));
			}
			return shader;
		}

		static std::shared_ptr<OpenGLProgram> Link(const std::string &name, const OpenGLShaders &shaders)
		{
			auto program = std::make_shared<OpenGLProgram>(name);
			shaders.Attach(*program);
			program->Link();
			if (!program->IsLinked())
			{
				throw ShaderCompilationException(fmt::format("Shader link failed: {}", program->GetInfoLog()));
			}
			shaders.Detach(*program);
			return program;
		}
	};
}