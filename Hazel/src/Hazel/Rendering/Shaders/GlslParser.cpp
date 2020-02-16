#include "GlslParser.h"

#include "ShaderType.h"

namespace Hazel
{
    const Regex GlslParser::pattern(R"(\#\s*type\s*(\w+)\s*)");

    std::unordered_map<ShaderType, std::string> GlslParser::Parse(const std::string &filename)
    {
        return SplitShaders(ReadFile(filename));
    }

    std::string GlslParser::ReadFile(const std::string &filename)
    {
        FILE *stream = nullptr;
        fopen_s(&stream, filename.c_str(), "rb");
        if (!stream)
        {
            CoreError("Cannot open shader source file {}", filename);
            failed = true;
            return "";
        }
        fseek(stream, 0, SEEK_END);
        size_t size = ftell(stream);
        std::string result;
        result.resize(size);
        rewind(stream);
        fread(result.data(), sizeof(char), size, stream);
        return result;
    }

    std::unordered_map<ShaderType, std::string> GlslParser::SplitShaders(const std::string &source)
    {
        std::unordered_map<ShaderType, std::string> sources;
        size_t start = 0;
        ShaderType type = ShaderType::Unknown;
        for (auto match : pattern.FindAll(source))
        {
            if (start && type != ShaderType::Unknown)
            {
                sources[type] = source.substr(start, match.position(0) - start);
            }
            type = ShaderType::FromKey(match[1]);
            if (type != ShaderType::Unknown)
            {
                start = match.position(0) + match[0].length();
            }
        }
        if (start && type != ShaderType::Unknown)
        {
            sources[type] = source.substr(start, source.size() - start);
        }
        failed = sources.size() < 2;
        return sources;
    }
}