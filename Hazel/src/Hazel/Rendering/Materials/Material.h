#pragma once

#include "glm/glm.hpp"

#include "Hazel/Rendering/Textures/SubTexture.h"
#include "MaterialShader.h"

namespace Hazel
{
	struct Material
	{
		glm::vec4 Color{1.0f};
		SubTexture Texture;
		std::shared_ptr<MaterialShader> Shader;
	};
}