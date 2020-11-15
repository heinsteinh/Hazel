#pragma once

#include "Hazel/Geometry/Size.h"
#include "TextureFormat.h"
#include "TextureFiltering.h"
#include "TextureWrapping.h"

namespace Hazel
{
	struct TextureInfo
	{
		Size Size;
		TextureFormat Format = TextureFormat::Rgba;
		TextureFiltering MinFilter = TextureFiltering::Linear;
		TextureFiltering MagFilter = TextureFiltering::Linear;
		TextureWrapping SWrap = TextureWrapping::Repeat;
		TextureWrapping TWrap = TextureWrapping::Repeat;
	};
}