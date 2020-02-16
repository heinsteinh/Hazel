#include "ColorFormat.h"

namespace Hazel
{
    const ColorFormat ColorFormat::Invalid(0);
    const ColorFormat ColorFormat::Rgb(3);
    const ColorFormat ColorFormat::Rgba(4);

    int ColorFormat::currentId = 0;

    std::unordered_map<int, ColorFormat> ColorFormat::formats = {
        {3, Rgb},
        {4, Rgba}
    };

    std::vector<std::string> ColorFormat::names = {
        "Invalid",
        "RGB",
        "RGBA"
    };

    ColorFormat::ColorFormat(int numChannels)
        : id(currentId++),
        numChannels(numChannels)
    {
    }
}