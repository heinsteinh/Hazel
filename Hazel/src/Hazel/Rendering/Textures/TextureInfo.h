#pragma once

#include "Image.h"
#include "ColorFormat.h"

namespace Hazel
{
    struct HAZEL_API TextureInfo
    {
        enum class Filter
        {
            Nearest,
            Linear
        };

        enum class Wrap
        {
            ClampToEdge,
            MirroredRepeat,
            Repeat
        };

        int Width = 0;
        int Height = 0;
        ColorFormat Format = ColorFormat::Rgba;
        Filter MinFilter = Filter::Linear;
        Filter MagFilter = Filter::Linear;
        Wrap SWrap = Wrap::Repeat;
        Wrap TWrap = Wrap::Repeat;

        static TextureInfo FromImage(const Image &image)
        {
            return {
                image.GetWidth(),
                image.GetHeight(),
                image.GetFormat()
            };
        }

        static TextureInfo FromSize(int width, int height)
        {
            return {width, height};
        }
    };
}