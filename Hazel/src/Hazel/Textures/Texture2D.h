#pragma once

#include "Texture.h"
#include "Hazel/Geometry/Size.h"

namespace Hazel
{
	class Texture2D : public Texture
	{
	public:
		virtual float GetHeight() const = 0;

		inline Size GetSize() const
		{
			return {GetWidth(), GetHeight()};
		}

		inline float GetAspectRatio() const
		{
			return GetSize().GetAspectRatio();
		}
	};
}