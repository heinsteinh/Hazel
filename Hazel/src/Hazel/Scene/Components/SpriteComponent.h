#pragma once

#include "Hazel/Rendering/Textures/SubTexture.h"

namespace Hazel
{
	struct SpriteComponent
	{
		glm::vec4 Color{1.0f};
		SubTexture Texture;
	};
}