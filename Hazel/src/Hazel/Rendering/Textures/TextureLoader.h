#pragma once

#include "ImageLoader.h"
#include "Texture.h"
#include "Hazel/Core/Window.h"

namespace Hazel
{
    class TextureLoader
    {
    private:
        Window &window;

    public:
        TextureLoader(Window &window)
            : window(window)
        {
        }

        SharedPtr<Texture> LoadFromImage(const std::string &filename)
        {
            ImageLoader loader;
            Image image = loader.Load(filename);
            auto texture = window.GetContext().GetFactory().CreateTexture2D(
                TextureInfo::FromImage(image));
            texture->SetData(image.GetData());
            return texture;
        }
    };
}