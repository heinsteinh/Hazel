#pragma once

#include "Hazel/Textures/SubTexture.h"

namespace Hazel
{
	struct SpriteComponent
	{
		glm::vec4 Color{1.0f};
		SubTexture Texture;
	};
}