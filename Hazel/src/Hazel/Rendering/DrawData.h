#pragma once

#include "Mesh.h"
#include "Hazel/Geometry/Transform.h"
#include "Hazel/Textures/SubTexture.h"

namespace Hazel
{
	struct DrawData
	{
		std::shared_ptr<Mesh> Mesh;
		Transform Transform;
		SubTexture Texture;
	};
}