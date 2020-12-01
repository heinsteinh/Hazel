#pragma once

#include "Hazel/Textures/SubTexture.h"

namespace Hazel
{
	struct TextureComponent
	{
		SubTexture Texture;

		TextureComponent() = default;

		TextureComponent(const SubTexture &texture)
			: Texture(texture)
		{
		}

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