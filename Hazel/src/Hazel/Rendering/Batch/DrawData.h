#pragma once

#include "Mesh.h"
#include "Hazel/Geometry/Transform.h"
#include "Hazel/Rendering/Textures/Texture2D.h"

namespace Hazel
{
	struct DrawData
	{
		std::vector<unsigned int> Indices;
		std::vector<Mesh> Meshes;
		Transform Transform;
		std::shared_ptr<Texture2D> Texture;
	};
}