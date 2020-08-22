#pragma once

#include "ColorFormat.h"
#include "TextureFiltering.h"
#include "TextureWrapping.h"

namespace Hazel
{
	struct TextureInfo
	{
		float Width = 0;
		float Height = 0;
		ColorFormat ColorFormat = ColorFormat::Rgba;
		TextureFiltering MinFilter = TextureFiltering::Linear;
		TextureFiltering MagFilter = TextureFiltering::Linear;
		TextureWrapping SWrap = TextureWrapping::Repeat;
		TextureWrapping TWrap = TextureWrapping::Repeat;
	};
}