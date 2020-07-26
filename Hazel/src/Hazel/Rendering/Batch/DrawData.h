#pragma once

#include "VertexInfo.h"
#include "Hazel/Geometry/Transform.h"
#include "Hazel/Rendering/Textures/Texture2D.h"

namespace Hazel
{
	struct DrawData
	{
		std::vector<unsigned int> Indices;
		std::vector<VertexInfo> Vertices;
		Transform Transform;
		std::shared_ptr<Texture2D> Texture;
	};
}