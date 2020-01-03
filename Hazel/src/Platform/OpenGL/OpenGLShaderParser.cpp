#include "OpenGLShaderParser.h"

#include "OpenGLDataType.h"
#include "Hazel/Utils/Regex.h"

namespace Hazel
{
    bool OpenGLShaderParser::Parse(const std::string &filename)
    {
        failed = false;
        sources.clear();
        SplitShaders(ReadFile(filename));
        return !failed;
    }

    std::string OpenGLShaderParser::ReadFile(const std::string &filename)
    {
        FILE *f = fopen(filename.c_str(), "rb");
        if (!f)
        {
            CoreError("Cannot open shader source file {}", filename);
            failed = true;
            return "";
        }
        std::string result;
        fseek(f, 0, SEEK_END);
        size_t size = ftell(f);
        result.resize(size);
        rewind(f);
        fread(result.data(), sizeof(char), size, f);
        fclose(f);
        return result;
    }

    void OpenGLShaderParser::SplitShaders(const std::string &source)
    {
        static const Regex pattern(R"(\#\s*type\s*(\w+)\s*)");
        size_t start = 0;
        unsigned int type = 0;
        for (const auto &match : pattern.Search(source))
        {
            if (start && type)
            {
                sources[type] = source.substr(start, match.position(0) - start);
            }
            if (type = OpenGLDataType::GetShaderType(match[1]))
            {
                start = match.position(0) + match[0].length();
            }
        }
        if (start && type)
        {
            sources[type] = source.substr(start, source.size() - start);
        }
    }
}