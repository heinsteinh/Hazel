#pragma once

#include "TextureInfo.h"

namespace Hazel
{
	class Texture
	{
	public:
		virtual ~Texture() = default;

		virtual const TextureInfo &GetInfo() const = 0;
		virtual void SetData(const void *data) = 0;
		virtual void *GetHandle() const = 0;

		inline Size GetSize() const
		{
			return GetInfo().Size;
		}

		inline float GetWidth() const
		{
			return GetSize().Width;
		}

		inline float GetHeight() const
		{
			return GetSize().Height;
		}

		inline float GetAspectRatio() const
		{
			return GetSize().GetAspectRatio();
		}
	};
}