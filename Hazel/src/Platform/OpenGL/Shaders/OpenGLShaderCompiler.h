#pragma once

#include "OpenGLProgram.h"

namespace Hazel
{
	class OpenGLShaderCompiler
	{
	public:
		static std::shared_ptr<OpenGLProgram> Compile(const ShaderInfo &info)
		{
			return Link(info.Name, CompileShaders(info.Sources));
		}

	private:
		static std::vector<OpenGLShader> CompileShaders(const ShaderSourceMap &sources)
		{
			std::vector<OpenGLShader> shaders;
			shaders.reserve(sources.GetSize());
			for (const auto &[type, source] : sources)
			{
				shaders.push_back(CompileShader(type, source));
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

		static std::shared_ptr<OpenGLProgram> Link(const std::string &name, const std::vector<OpenGLShader> &shaders)
		{
			auto program = std::make_shared<OpenGLProgram>(name);
			for (const auto &shader : shaders)
			{
				program->Attach(shader);
			}
			program->Link();
			if (!program->IsLinked())
			{
				throw ShaderCompilationException(fmt::format("Shader link failed: {}", program->GetInfoLog()));
			}
			for (const auto &shader : shaders)
			{
				program->Detach(shader);
			}
			return program;
		}
	};
}