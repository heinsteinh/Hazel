#pragma once

#include "Hazel/Core/DataType.h"
#include "Hazel/Rendering/Shaders/ShaderType.h"
#include "Hazel/Rendering/Textures/TextureFiltering.h"
#include "Hazel/Rendering/Textures/TextureWrapping.h"
#include "Hazel/Rendering/Textures/ColorFormat.h"

namespace Hazel
{
    class OpenGLConvert
    {
    private:
        static const std::unordered_map<DataType, unsigned int> dataTypes;
        static const std::unordered_map<ShaderType, unsigned int> shaderTypes;
        static const std::unordered_map<TextureFiltering, unsigned int> filters;
        static const std::unordered_map<TextureWrapping, unsigned int> wraps;
        static const std::unordered_map<ColorFormat, unsigned int> colorFormats;

    public:
        static inline unsigned int ToInternal(DataType type)
        {
            auto i = dataTypes.find(type);
            return i == dataTypes.end() ? 0 : i->second;
        }

        static inline unsigned int ToInternal(ShaderType type)
        {
            auto i = shaderTypes.find(type);
            return i == shaderTypes.end() ? 0 : i->second;
        }

        static inline unsigned int ToInternal(TextureFiltering filter)
        {
            auto i = filters.find(filter);
            return i == filters.end() ? 0 : i->second;
        }

        static inline unsigned int ToInternal(TextureWrapping wrap)
        {
            auto i = wraps.find(wrap);
            return i == wraps.end() ? 0 : i->second;
        }

        static inline unsigned ToInternal(ColorFormat colorFormat)
        {
            auto i = colorFormats.find(colorFormat);
            return i == colorFormats.end() ? 0 : i->second;
        }

        OpenGLConvert() = delete;
    };
}