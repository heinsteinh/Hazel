#include "ShaderLanguage.h"

namespace Hazel
{
    const ShaderLanguage ShaderLanguage::Unknown;
    const ShaderLanguage ShaderLanguage::Glsl;

    int ShaderLanguage::currentId = 0;

    std::vector<std::string> ShaderLanguage::names = {
        "Unknown",
        "GLSL"
    };

    const std::unordered_map<std::string, ShaderLanguage> ShaderLanguage::extensions = {
        {"glsl", Glsl}
    };

    ShaderLanguage::ShaderLanguage()
        : id(currentId++)
    {
    }
}