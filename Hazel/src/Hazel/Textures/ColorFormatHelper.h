#pragma once

#include "ColorFormat.h"

namespace Hazel
{
	class ColorFormatHelper
	{
	public:
		static constexpr ColorFormat CreateFromNumChannels(int numChannels)
		{
			switch (numChannels)
			{
			case 3:
				return ColorFormat::Rgb;
			case 4:
				return ColorFormat::Rgba;
			default:
				return ColorFormat::Unknown;
			}
		}

		static constexpr int GetNumChannels(ColorFormat format)
		{
			switch (format)
			{
			case ColorFormat::Rgb:
				return 3;
			case ColorFormat::Rgba:
				return 4;
			default:
				return 0;
			}
		}

		ColorFormatHelper() = delete;
	};
}