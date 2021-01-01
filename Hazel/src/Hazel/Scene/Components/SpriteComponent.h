#pragma once

#include <string>

#include "glm/glm.hpp"

#include "Hazel/Rendering/Textures/SubTexture.h"

namespace Hazel
{
	struct SpriteComponent
	{
		glm::vec4 Color{1.0f};
		SubTexture Texture;
		std::string TextureFilename;
	};
}