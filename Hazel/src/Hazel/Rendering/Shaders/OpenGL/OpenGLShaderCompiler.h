#pragma once

#include <memory>

#include "spdlog/fmt/fmt.h"
#include "glad/glad.h"

#include "OpenGLProgram.h"
#include "Private/OpenGLShaders.h"

namespace Hazel
{
	class OpenGLShaderCompiler
	{
	public:
		static std::shared_ptr<OpenGLProgram> Compile(const ShaderInfo &info)
		{
			if (info.VertexSource.empty() || info.PixelSource.empty())
			{
				throw ShaderCompilationException("The shader must at least contain vertex and pixel sources.");
			}
			return Link(CompileShaders(info));
		}

	private:
		static OpenGLShaders CompileShaders(const ShaderInfo &info)
		{
			OpenGLShaders shaders;
			shaders.AddVertexShader(CompileShader(GL_VERTEX_SHADER, info.VertexSource));
			shaders.AddPixelShader(CompileShader(GL_FRAGMENT_SHADER, info.PixelSource));
			return shaders;
		}

		static OpenGLShader CompileShader(int shaderType, const std::string &source)
		{
			OpenGLShader shader(shaderType, source);
			if (!shader.IsCompiled())
			{
				throw ShaderCompilationException(fmt::format("Shader compilation failed: {}", shader.GetInfoLog()));
			}
			return shader;
		}

		static std::shared_ptr<OpenGLProgram> Link(const OpenGLShaders &shaders)
		{
			auto program = std::make_shared<OpenGLProgram>();
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