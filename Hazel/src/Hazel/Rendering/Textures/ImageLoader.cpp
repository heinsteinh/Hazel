#include "ImageLoader.h"

#include "stb_image.h"

namespace Hazel
{
    Image ImageLoader::Load(const std::string &filename)
    {
        stbi_set_flip_vertically_on_load(flipVertically ? 1 : 0);
        return filename;
    }
}