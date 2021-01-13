#pragma once

#include <optional>

#include "Hazel/Rendering/GraphicsContext/PrimitiveTopology.h"
#include "IndexArray.h"
#include "VertexArray.h"

namespace Hazel
{
	struct Mesh
	{
		PrimitiveTopology PrimitiveTopology = PrimitiveTopology::Triangles;
		IndexArray Indices;
		VertexArray Vertices;
		std::optional<size_t> PositionIndex;
		std::optional<size_t> ColorIndex;
		std::optional<size_t> TextureCoordinatesIndex;
		std::optional<size_t> TextureSlotIndex;
	};
}