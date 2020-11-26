#pragma once

#include "TextureInfo.h"

namespace Hazel
{
	class Texture
	{
	private:
		TextureInfo info;

	public:
		inline Texture(const TextureInfo &info)
			: info(info)
		{
		}

		virtual ~Texture() = default;

		virtual void BufferData(const void *data) = 0;
		virtual void *GetHandle() const = 0;

		constexpr const TextureInfo &GetInfo() const
		{
			return info;
		}

		constexpr TextureFormat GetFormat() const
		{
			return info.Format;
		}

		constexpr Size GetSize() const
		{
			return info.Size;
		}

		constexpr float GetWidth() const
		{
			return info.Size.Width;
		}

		constexpr float GetHeight() const
		{
			return info.Size.Height;
		}

		constexpr float GetAspectRatio() const
		{
			return info.Size.GetAspectRatio();
		}
	};
}