#pragma once

#include "Hazel/Core/Utils/StaticCast.h"
#include "Hazel/Rendering/GraphicsContext/OpenGL/OpenGLBindingContext.h"
#include "Hazel/Rendering/GraphicsContext/OpenGL/OpenGLBinder.h"
#include "Hazel/Rendering/GraphicsContext/DrawCommand.h"

namespace Hazel
{
	class OpenGLShaderBinder
	{
	public:
		static void BindShader(OpenGLBindingContext &context, const DrawCommand &command)
		{
			auto openGLShader = StaticCast::Convert<OpenGLShader>(command.Shader.lock());
			if (openGLShader)
			{
				BindProgram(context, *openGLShader);
				BindVertexArray(context, command, *openGLShader);
			}
			else
			{
				context.SetProgram(nullptr);
				context.SetVertexArray(nullptr);
			}
		}

	private:
		static void BindProgram(OpenGLBindingContext &context, OpenGLShader &shader)
		{
			if (context.SetProgram(shader.GetProgram()) || shader.IsUniformUpdated())
			{
				BufferUniform(context, shader);
				shader.ResetUniformUpdated();
			}
		}

		static void BufferUniform(OpenGLBindingContext &context, OpenGLShader &shader)
		{
			auto &uniform = shader.GetUniform();
			auto uniformSize = uniform.GetSize();
			context.EnsureUniformBufferSize(uniformSize).BufferData(uniform.GetData(), uniformSize);
		}

		static void BindVertexArray(OpenGLBindingContext &context, const DrawCommand &command, OpenGLShader &shader)
		{
			auto &vertexArray = shader.GetVertexArray();
			context.SetVertexArray(vertexArray);
			vertexArray->SetIndexBuffer(command.IndexBuffer.lock());
			vertexArray->SetVertexBuffer(command.VertexBuffer.lock(), shader.GetInputLayout());
		}
	};
}