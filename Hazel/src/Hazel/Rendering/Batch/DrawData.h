#pragma once

#include "Mesh.h"
#include "Hazel/Utils/Transform.h"

namespace Hazel
{
	struct DrawData
	{
		std::vector<unsigned int> Indexes;
		std::vector<Mesh> Meshes;
		Transform Transform;
	};
}