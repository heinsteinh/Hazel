#pragma once

#include "Hazel/Rendering/Renderer/RendererException.h"
#include "RendererContext.h"
#include "RendererShaderManager.h"
#include "RendererMeshManager.h"
#include "RendererDrawCall.h"

namespace Hazel
{
	class RendererSubmission
	{
	public:
		static void Submit(RendererContext &context, const RenderCommand &command)
		{
			SetupShader(context, command);
			SetupMeshFormat(context, command);
			if (!AddVertices(context, command))
			{
				throw RendererException("The batch is too small for the object.");
			}
		}

	private:
		static void SetupShader(RendererContext &context, const RenderCommand &command)
		{
			if (!RendererShaderManager::HasShader(context, *command.Shader))
			{
				RendererDrawCall::Flush(context);
				RendererShaderManager::SetShader(context, *command.Shader);
			}
		}

		static void SetupMeshFormat(RendererContext &context, const RenderCommand &command)
		{
			if (!RendererMeshManager::HasMeshFormat(context, *command.Mesh))
			{
				RendererDrawCall::Flush(context);
				RendererMeshManager::SetMeshFormat(context, *command.Mesh);
			}
		}

		static bool AddVertices(RendererContext &context, const RenderCommand &command)
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