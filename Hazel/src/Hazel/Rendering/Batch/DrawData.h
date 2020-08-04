#pragma once

#include "Mesh.h"
#include "Hazel/Geometry/Transform.h"
#include "Hazel/Rendering/Textures/Texture2D.h"

namespace Hazel
{
	struct DrawData
	{
		Mesh Mesh;
		Transform Transform;
		std::shared_ptr<Texture2D> Texture;
	};
}