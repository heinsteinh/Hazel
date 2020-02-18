#include "Image.h"

#include "stb_image.h"

#include "ColorFormatInfo.h"

namespace Hazel
{
    Image::Image(const std::string &filename)
    {
        int numChannels = 0;
        data = stbi_load(filename.c_str(), &width, &height, &numChannels, 0);
        format = ColorFormatInfo::FromNumChannels(numChannels);
    }

    Image::Image(Image &&other) noexcept
        : width(other.width),
        height(other.height),
        format(other.format),
        data(other.ReleaseData())
    {
    }

    Image::~Image()
    {
        FreeData();
    }

    void *Image::ReleaseData()
    {
        width = height = 0;
        void *temp = data;
        data = nullptr;
        return temp;
    }

    Image &Image::operator=(Image &&other)
    {
        width = other.width;
        height = other.height;
        format = other.format;
        data = other.ReleaseData();
        return *this;
    }

    void Image::FreeData()
    {
        width = height = 0;
        if (data)
        {
            stbi_image_free(data);
        }
    }
}