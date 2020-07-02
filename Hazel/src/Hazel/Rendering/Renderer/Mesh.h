#pragma once

#include "Hazel/Rendering/Textures/Texture2D.h"
#include "Vertex.h"

namespace Hazel
{
	struct Mesh
	{
		glm::vec3 Position = {0.0f, 0.0f, 0.0f};
		glm::vec2 TextureCoordinate{0.0f};
		glm::vec4 Color{1.0f};
		std::shared_ptr<Texture2D> Texture;
	};
}