#pragma once

#include "Hazel/Textures/SubTexture.h"

namespace Hazel
{
	struct TextureComponent
	{
		SubTexture Texture;

		operator SubTexture &()
		{
			return Texture;
		}

		operator const SubTexture &() const
		{
			return Texture;
		}
	};
}