#pragma once

#include "Mesh.h"
#include "Hazel/Geometry/Transform.h"
#include "Hazel/Textures/SubTexture.h"

namespace Hazel
{
	struct DrawData
	{
		Mesh Mesh;
		Transform Transform;
		SubTexture Texture;
	};
}