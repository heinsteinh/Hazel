#pragma once

#include <string>

#include "glm/glm.hpp"

#include "TextureFormat.h"
#include "TextureFilterMode.h"
#include "TextureWrapMode.h"

namespace Hazel
{
	struct TextureInfo
	{
		std::string Name;
		std::string Filename;
		glm::vec2 Size{1.0f};
		TextureFormat Format = TextureFormat::Rgba8;
		TextureFilterMode MinFilterMode = TextureFilterMode::Linear;
		TextureFilterMode MagFilterMode = TextureFilterMode::Linear;
		TextureWrapMode WrapModeU = TextureWrapMode::Repeat;
		TextureWrapMode WrapModeV = TextureWrapMode::Repeat;
	};
}