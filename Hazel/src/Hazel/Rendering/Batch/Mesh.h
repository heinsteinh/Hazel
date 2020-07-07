#pragma once

#include "Vertex.h"

namespace Hazel
{
	struct Mesh
	{
		glm::vec4 Position = {0.0f, 0.0f, 0.0f, 1.0f};
		glm::vec2 TextureCoordinate{0.0f};
		glm::vec4 Color{1.0f};
	};
}