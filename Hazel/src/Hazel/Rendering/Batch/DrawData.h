#pragma once

#include "Mesh.h"
#include "Hazel/Rendering/Textures/Texture2D.h"

namespace Hazel
{
	struct DrawData
	{
		Mesh Mesh;
		glm::mat4 Transform{1.0f};
		std::shared_ptr<Texture2D> Texture;
	};
}