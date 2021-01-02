#pragma once

#include <memory>

#include "Mesh.h"

namespace Hazel
{
	class SquareMesh
	{
	private:
		static const std::shared_ptr<const Mesh> mesh;

	public:
		static std::shared_ptr<Mesh> CreateMesh();

		static const Mesh &GetMesh()
		{
			return *mesh;
		}
	};
}