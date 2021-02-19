#pragma once

#include "RendererContext.h"

namespace Hazel
{
	class RendererMeshFormat
	{
	public:
		static bool HasMeshFormat(RendererContext &context, const Mesh &mesh)
		{
			return context.Command.PrimitiveTopology == mesh.PrimitiveTopology;
		}

		static void SetMeshFormat(RendererContext &context, const Mesh &mesh)
		{
			context.Command.PrimitiveTopology = mesh.PrimitiveTopology;
		}
	};
}