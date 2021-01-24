#pragma once

#include "RendererContext.h"

namespace Hazel
{
	class RendererMeshManager
	{
	public:
		static bool HasMeshFormat(RendererContext &context, const Mesh &mesh)
		{
			return context.Command.PrimitiveTopology == mesh.PrimitiveTopology
				&& context.Command.IndexFormat == mesh.Indices.GetIndexFormat();
		}

		static void SetMeshFormat(RendererContext &context, const Mesh &mesh)
		{
			context.Command.PrimitiveTopology = mesh.PrimitiveTopology;
			context.Command.IndexFormat = mesh.Indices.GetIndexFormat();
			context.Batch.SetIndexFormat(context.Command.IndexFormat);
		}
	};
}