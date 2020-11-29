#pragma once

#include "TextureFormat.h"
#include "TextureFiltering.h"
#include "TextureWrapping.h"

namespace Hazel
{
	struct TextureInfo
	{
		glm::vec2 Size{1.0f};
		TextureFormat Format = TextureFormat::Rgba8;
		TextureFiltering MinFilter = TextureFiltering::Linear;
		TextureFiltering MagFilter = TextureFiltering::Linear;
		TextureWrapping SWrap = TextureWrapping::Repeat;
		TextureWrapping TWrap = TextureWrapping::Repeat;
	};
}