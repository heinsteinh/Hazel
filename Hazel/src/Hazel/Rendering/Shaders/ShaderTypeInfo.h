#pragma once

#include "ShaderType.h"

namespace Hazel
{
    class ShaderTypeInfo
    {
    private:
        static inline std::unordered_map<ShaderType, std::string> keys = {
            {ShaderType::Unknown, "unknown"},
            {ShaderType::Vertex, "vertex"},
            {ShaderType::Pixel, "pixel"}
        };

        static inline std::unordered_map<std::string, ShaderType> types = {
            {"vertex", ShaderType::Vertex},
            {"pixel", ShaderType::Pixel},
            {"fragment", ShaderType::Pixel}
        };

    public:
        static inline ShaderType GetType(const std::string &key)
        {
            auto i = types.find(key);
            return i == types.end() ? ShaderType::Unknown : i->second;
        }

        static inline const std::string &GetKey(ShaderType type)
        {
            auto i = keys.find(type);
            return i == keys.end() ? keys.at(ShaderType::Unknown) : i->second;
        }

        ShaderTypeInfo() = delete;
    };
}