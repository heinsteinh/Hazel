#pragma once

#include "ShaderType.h"
#include "Hazel/Utils/Regex.h"

namespace Hazel
{
    class GlslParser
    {
    private:
        static const Regex pattern;

        bool failed = false;

    public:
        GlslParser() = default;

        std::unordered_map<ShaderType, std::string> Parse(const std::string &filename);

        inline bool HasFailed() const
        {
            return failed;
        }

    private:
        std::string ReadFile(const std::string &filename);
        std::unordered_map<ShaderType, std::string> SplitShaders(const std::string &source);
    };
}