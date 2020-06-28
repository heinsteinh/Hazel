#pragma once

#include "Mesh.h"

namespace Hazel
{
	struct DrawData
	{
		std::vector<unsigned int> Indexes;
		std::vector<Mesh> Meshes;
	};
}