#pragma once

#include "Texture.h"

namespace Hazel
{
	class Texture2D : public Texture
	{
	public:
		virtual size_t GetHeight() const = 0;
	};
}