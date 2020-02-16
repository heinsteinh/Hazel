#pragma once

#include "ColorFormat.h"

namespace Hazel
{
    class Image
    {
    private:
        int width = 0;
        int height = 0;
        ColorFormat format;
        void *data = nullptr;

    public:
        Image() = default;

        Image(const std::string &filename);
        Image(const Image &other) = delete;
        Image(Image &&other) noexcept;

        ~Image();

        void *ReleaseData();

        Image &operator=(const Image &other) = delete;
        Image &operator=(Image &&other);

        inline int GetWidth() const
        {
            return width;
        }

        inline int GetHeight() const
        {
            return height;
        }

        inline ColorFormat GetFormat() const
        {
            return format;
        }

        inline void *GetData() const
        {
            return data;
        }

    private:
        inline void FreeData();
    };
}