#pragma once

#include "Hazel/Core/Exceptions/AssertionException.h"
#include "Hazel/Rendering/Renderer/RendererException.h"
#include "RendererPrivate.h"
#include "RendererShader.h"
#include "RendererMeshFormat.h"
#include "RendererDrawCall.h"

namespace Hazel
{
	class RendererSubmission
	{
	public:
		static void Submit(RendererPrivate &context, const RenderCommand &command)
		{
			HZ_ASSERT(command.IsValid(), "Render command needs at least a mesh and a shader");
			SetupShader(context, command);
			SetupMeshFormat(context, command);
			if (!AddVertices(context, command))
			{
				throw RendererException("The batch is too small for the object.");
			}
		}

	private:
		static void SetupShader(RendererPrivate &context, const RenderCommand &command)
		{
			if (!RendererShader::HasShader(context, command.Shader))
			{
				RendererDrawCall::Flush(context);
				RendererShader::SetShader(context, command.Shader);
			}
		}

		static void SetupMeshFormat(RendererPrivate &context, const RenderCommand &command)
		{
			if (!RendererMeshFormat::HasMeshFormat(context, *command.Mesh))
			{
				RendererDrawCall::Flush(context);
				RendererMeshFormat::SetMeshFormat(context, *command.Mesh);
			}
		}

		static bool AddVertices(RendererPrivate &context, const RenderCommand &command)
		{
			if (!context.Batch.Add(command))
			{
				RendererDrawCall::Flush(context);
				return context.Batch.Add(command);
			}
			return true;
		}
	};
}