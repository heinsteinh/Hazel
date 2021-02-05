#pragma once

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
	};
}