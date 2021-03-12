#pragma once

#include "TextureFormat.h"

namespace Hazel
{
	class TextureFormatHelper
	{
	public:
		static constexpr TextureFormat GetTextureFormat(int numChannels)
		{
			switch (numChannels)
			{
			case 3:
				return TextureFormat::Rgb8;
			case 4:
				return TextureFormat::Rgba8;
			}
			return TextureFormat::Rgba8;
		}

		static constexpr int GetChannelCount(TextureFormat format)
		{
			switch (format)
			{
			case TextureFormat::Rgb8:
				return 3;
			case TextureFormat::Rgba8:
				return 4;
			}
			return 0;
		}
	};
}