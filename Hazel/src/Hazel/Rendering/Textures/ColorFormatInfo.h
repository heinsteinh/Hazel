#pragma once

#include "ColorFormat.h"

namespace Hazel
{
    class ColorFormatInfo
    {
    private:
        const ColorFormat format;

    public:
        static constexpr ColorFormat FromNumChannels(int numChannels)
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

        constexpr int GetNumChannels()
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
    };
}