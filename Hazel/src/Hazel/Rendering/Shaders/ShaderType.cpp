#include "ShaderType.h"

namespace Hazel
{
    const ShaderType ShaderType::Unknown;
    const ShaderType ShaderType::Vertex;
    const ShaderType ShaderType::Pixel;

    int ShaderType::currentId = 0;

    inline std::vector<std::string> ShaderType::keys = {
        "unknown",
        "vertex",
        "pixel"
    };

    inline std::unordered_map<std::string, ShaderType> ShaderType::shaderTypes = {
        {Unknown.GetKey(), Unknown},
        {Vertex.GetKey(), Vertex},
        {Pixel.GetKey(), Pixel},
        {"fragment", Pixel}
    };

    ShaderType::ShaderType()
        : id(currentId++)
    {
    }
}