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
				return TextureFormat::Rgb;
			case 4:
				return TextureFormat::Rgba;
			default:
				return TextureFormat::Unknown;
			}
		}

		static constexpr int GetChannelCount(TextureFormat format)
		{
			switch (format)
			{
			case TextureFormat::Rgb:
				return 3;
			case TextureFormat::Rgba:
				return 4;
			default:
				return 0;
			}
		}

		TextureFormatHelper() = delete;
	};
}