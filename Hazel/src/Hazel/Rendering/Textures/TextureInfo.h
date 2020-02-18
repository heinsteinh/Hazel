#pragma once

#include "Image.h"
#include "ColorFormat.h"
#include "TextureFiltering.h"
#include "TextureWrapping.h"

namespace Hazel
{
    struct HAZEL_API TextureInfo
    {
        int Width = 0;
        int Height = 0;
        ColorFormat Format = ColorFormat::Rgba;
        TextureFiltering MinFilter = TextureFiltering::Linear;
        TextureFiltering MagFilter = TextureFiltering::Linear;
        TextureWrapping SWrap = TextureWrapping::Repeat;
        TextureWrapping TWrap = TextureWrapping::Repeat;

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