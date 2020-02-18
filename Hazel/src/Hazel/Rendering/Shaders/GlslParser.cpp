#include "GlslParser.h"

#include "ShaderTypeInfo.h"
#include "Hazel/Utils/FileReader.h"

namespace Hazel
{
    const Regex GlslParser::pattern(R"(\#\s*type\s*(\w+)\s*)");

    std::unordered_map<ShaderType, std::string> GlslParser::Parse(const std::string &filename)
    {
        return SplitShaders(FileReader().ReadAll(filename));
    }

    std::unordered_map<ShaderType, std::string> GlslParser::SplitShaders(const std::string &source)
    {
        std::unordered_map<ShaderType, std::string> sources;
        size_t start = 0;
        ShaderType type = ShaderType::Unknown;
        for (auto match : pattern.FindAll(source))
        {
            if (start != 0 && type != ShaderType::Unknown)
            {
                sources[type] = source.substr(start, match.position(0) - start);
            }
            type = ShaderTypeInfo::GetType(match[1]);
            if (type != ShaderType::Unknown)
            {
                start = match.position(0) + match[0].length();
            }
        }
        if (start != 0 && type != ShaderType::Unknown)
        {
            sources[type] = source.substr(start, source.size() - start);
        }
        failed = sources.size() < 2;
        return sources;
    }
}