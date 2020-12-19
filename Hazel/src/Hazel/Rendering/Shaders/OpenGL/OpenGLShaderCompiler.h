#pragma once

#include <vector>
#include <memory>

#include "OpenGLProgram.h"

namespace Hazel
{
	class OpenGLShaderCompiler
	{
	public:
		using CompiledShaders = std::array<OpenGLShader, static_cast<size_t>(ShaderType::Count)>;

		static std::shared_ptr<OpenGLProgram> Compile(const ShaderInfo &info)
		{
			if (!info.Sources.IsValid())
			{
				throw ShaderCompilationException("Shader must at least contain vertex and pixel sources.");
			}
			return Link(info.Name, CompileShaders(info.Sources));
		}

	private:
		static CompiledShaders CompileShaders(const ShaderSourceMap &sources)
		{
			CompiledShaders shaders;
			for (const auto &[type, source] : sources)
			{
				if (!source.empty())
				{
					shaders[static_cast<size_t>(type)] = CompileShader(type, source);
				}
			}
			return shaders;
		}

		static OpenGLShader CompileShader(ShaderType type, const std::string &source)
		{
			OpenGLShader shader(type, source);
			if (!shader.IsCompiled())
			{
				throw ShaderCompilationException(fmt::format("Shader {} compilation failed: {}", type, shader.GetInfoLog()));
			}
			return shader;
		}

		static std::shared_ptr<OpenGLProgram> Link(const std::string &name, const CompiledShaders &shaders)
		{
			auto program = std::make_shared<OpenGLProgram>(name);
			for (const auto &shader : shaders)
			{
				if (shader.IsValid())
				{
					program->Attach(shader);
				}
			}
			program->Link();
			if (!program->IsLinked())
			{
				throw ShaderCompilationException(fmt::format("Shader link failed: {}", program->GetInfoLog()));
			}
			for (const auto &shader : shaders)
			{
				if (shader.IsValid())
				{
					program->Detach(shader);
				}
			}
			return program;
		}
	};
}