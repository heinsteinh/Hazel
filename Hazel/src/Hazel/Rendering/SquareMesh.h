#pragma once

#include "Mesh.h"

namespace Hazel
{
	class SquareMesh
	{
	public:
		static std::shared_ptr<Mesh> CreateMesh();
	};
}