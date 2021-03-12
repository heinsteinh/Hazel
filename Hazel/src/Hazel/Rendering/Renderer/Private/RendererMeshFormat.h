#pragma once

#include "RendererPrivate.h"

namespace Hazel
{
	class RendererMeshFormat
	{
	public:
		static bool HasMeshFormat(RendererPrivate &context, const Mesh &mesh)
		{
			return context.Command.PrimitiveTopology == mesh.PrimitiveTopology;
		}

		static void SetMeshFormat(RendererPrivate &context, const Mesh &mesh)
		{
			context.Command.PrimitiveTopology = mesh.PrimitiveTopology;
		}
	};
}