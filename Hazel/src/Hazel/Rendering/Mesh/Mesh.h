#pragma once

#include <optional>

#include "Hazel/Rendering/Shaders/ShaderInputMap.h"
#include "PrimitiveTopology.h"
#include "IndexArray.h"
#include "VertexArray.h"

namespace Hazel
{
	struct Mesh
	{
		PrimitiveTopology PrimitiveTopology = PrimitiveTopology::Triangles;
		IndexArray Indices;
		VertexArray Vertices;
		ShaderInputMap InputMap;
	};
}