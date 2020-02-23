#pragma once

#include "ImageLoader.h"
#include "Texture.h"
#include "Hazel/Core/Window.h"

namespace Hazel
{
    class TextureBuilder
    {
    private:
        Window &window;

    public:
        TextureBuilder(Window &window)
            : window(window)
        {
        }

        inline SharedPtr<Texture2D> Build(const std::string &filename)
        {
            Image image = ImageLoader().Load(filename);
            auto texture = window.GetContext().GetFactory().CreateTexture2D(
                {image.GetWidth(), image.GetHeight(), image.GetFormat()});
            texture->SetData(image.GetData());
            return texture;
        }

        inline SharedPtr<Texture2D> Build(const glm::vec4 &data)
        {
            auto texture = window.GetContext().GetFactory().CreateTexture2D({1, 1, ColorFormat::Rgba});
            unsigned char color[4] = {
                (unsigned char)(data.r * 255.0f),
                (unsigned char)(data.g * 255.0f),
                (unsigned char)(data.b * 255.0f),
                (unsigned char)(data.a * 255.0f)
            };
            texture->SetData(color);
            return texture;
        }
    };
}