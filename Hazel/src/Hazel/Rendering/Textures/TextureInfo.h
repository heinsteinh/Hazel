#pragma once

#include <string>

#include "glm/glm.hpp"

#include "TextureFormat.h"
#include "TextureFiltering.h"
#include "TextureWrapping.h"

namespace Hazel
{
	struct TextureInfo
	{
		std::string Name;
		std::string Filename;
		glm::vec2 Size{1.0f};
		const void *Data = nullptr;
		TextureFormat Format = TextureFormat::Rgba8;
		TextureFiltering MinFilter = TextureFiltering::Linear;
		TextureFiltering MagFilter = TextureFiltering::Linear;
		TextureWrapping WrapS = TextureWrapping::Repeat;
		TextureWrapping WrapT = TextureWrapping::Repeat;
	};
}