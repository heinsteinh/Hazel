#pragma once

#include "Image.h"
#include "ColorFormat.h"
#include "TextureFiltering.h"
#include "TextureWrapping.h"

namespace Hazel
{
    struct HAZEL_API TextureInfo
    {
        int width = 0;
        int height = 0;
        ColorFormat colorFormat = ColorFormat::Rgba;
        TextureFiltering minFilter = TextureFiltering::Linear;
        TextureFiltering magFilter = TextureFiltering::Linear;
        TextureWrapping sWrap = TextureWrapping::Repeat;
        TextureWrapping tWrap = TextureWrapping::Repeat;

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