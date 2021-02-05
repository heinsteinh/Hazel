#pragma once

#include "Hazel/Core/Utils/EnumMap.h"
#include "Hazel/Rendering/Shaders/OpenGL/OpenGLProgram.h"

namespace Hazel
{
	class OpenGLShaderModules
	{
	private:
		EnumMap<ShaderType, OpenGLShaderModule> shaders;

	public:
		void Attach(OpenGLProgram &program) const
		{
			shaders.ForEach([&](auto shaderType, const auto &shader)
			{
				if (shader.IsValid())
				{
					program.Attach(shader);
				}
			});
		}

		void Detach(OpenGLProgram &program) const
		{
			shaders.ForEach([&](auto shaderType, const auto &shader)
			{
				if (shader.IsValid())
				{
					program.Detach(shader);
				}
			});
		}

		const OpenGLShaderModule &operator[](ShaderType shaderType) const
		{
			return shaders[shaderType];
		}

		OpenGLShaderModule &operator[](ShaderType shaderType)
		{
			return shaders[shaderType];
		}

		template<typename FunctorType>
		void ForEach(FunctorType functor) const
		{
			shaders.ForEach(functor);
		}

		template<typename FunctorType>
		void ForEach(FunctorType functor)
		{
			shaders.ForEach(functor);
		}
	};
}