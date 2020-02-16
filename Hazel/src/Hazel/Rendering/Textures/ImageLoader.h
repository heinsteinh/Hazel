#pragma once

#include "Image.h"

namespace Hazel
{
    class ImageLoader
    {
    private:
        bool flipVertically = true;

    public:
        ImageLoader() = default;

        Image Load(const std::string &filename);

        inline bool DoesFilpVertically() const
        {
            return flipVertically;
        }

        inline void SetFlipVertically(bool flipVertically)
        {
            this->flipVertically = flipVertically;
        }
    };
}