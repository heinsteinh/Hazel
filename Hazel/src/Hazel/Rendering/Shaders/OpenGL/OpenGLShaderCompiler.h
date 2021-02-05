#pragma once

#include <memory>

#include "spdlog/fmt/fmt.h"
#include "glad/glad.h"

#include "Hazel/Rendering/Shaders/ShaderTypeName.h"
#include "OpenGLShader.h"
#include "OpenGLProgram.h"
#include "OpenGLShaderType.h"
#include "Private/OpenGLShaderModules.h"

namespace Hazel
{
	class OpenGLShaderCompiler
	{
	public:
		static std::shared_ptr<OpenGLShader> Compile(const ShaderInfo &info)
		{
			return std::make_shared<OpenGLShader>(info, Link(CompileShaders(info.Sources)));
		}

	private:
		static std::shared_ptr<OpenGLProgram> Link(const OpenGLShaderModules &shaders)
		{
			auto program = std::make_shared<OpenGLProgram>();
			shaders.Attach(*program);
			program->Link();
			if (!program->IsLinked())
			{
				throw ShaderCompilationException(fmt::format("Program link failed: {}", program->GetInfoLog()));
			}
			shaders.Detach(*program);
			return program;
		}

		static OpenGLShaderModules CompileShaders(const EnumMap<ShaderType, std::string> &sources)
		{
			OpenGLShaderModules shaders;
			sources.ForEach([&](auto shaderType, const auto &source)
			{
				shaders[shaderType] = CompileShader(shaderType, source);
			});
			return shaders;
		}

		static OpenGLShaderModule CompileShader(ShaderType shaderType, const std::string &source)
		{
			OpenGLShaderModule shader(OpenGLShaderType::GetShaderType(shaderType), source);
			if (!shader.IsCompiled())
			{
				throw ShaderCompilationException(fmt::format(
					"Compilation of {} shader failed: {}",
					ShaderTypeName::GetName(shaderType),
					shader.GetInfoLog()));
			}
			return shader;
		}
	};
}