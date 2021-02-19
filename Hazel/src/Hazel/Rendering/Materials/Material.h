#pragma once

#include "glm/glm.hpp"

#include "Hazel/Rendering/Shaders/Shader.h"
#include "Hazel/Rendering/Textures/SubTexture.h"

namespace Hazel
{
	struct Material
	{
		glm::vec4 Color{1.0f};
		SubTexture Texture;
		std::shared_ptr<Shader> Shader;
		bool Transparency = false;
	};
}