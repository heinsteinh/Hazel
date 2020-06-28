#pragma once

#include "ColorFormat.h"
#include "TextureFiltering.h"
#include "TextureWrapping.h"

namespace Hazel
{
	struct TextureInfo
	{
		size_t Width = 0;
		size_t Height = 0;
		ColorFormat ColorFormat = ColorFormat::Rgba;
		TextureFiltering MinFilter = TextureFiltering::Linear;
		TextureFiltering MagFilter = TextureFiltering::Linear;
		TextureWrapping SWrap = TextureWrapping::Repeat;
		TextureWrapping TWrap = TextureWrapping::Repeat;
	};
}