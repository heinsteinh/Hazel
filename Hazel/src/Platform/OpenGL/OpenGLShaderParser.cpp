#include "OpenGLShaderParser.h"

#include "OpenGLDataType.h"
#include "Hazel/Utils/Regex.h"

namespace Hazel
{
    bool OpenGLShaderParser::Parse(const std::string &filename)
    {
        Reset();
        SplitShaders(ReadFile(filename));
        return !failed;
    }

    void OpenGLShaderParser::Reset()
    {
        failed = false;
        sources.clear();
    }

    std::string OpenGLShaderParser::ReadFile(const std::string &filename)
    {
        FILE *stream = nullptr;
        fopen_s(&stream, filename.c_str(), "rb");
        if (!stream)
        {
            CoreError("Cannot open shader source file {}", filename);
            failed = true;
            return "";
        }
        std::string result;
        fseek(stream, 0, SEEK_END);
        size_t size = ftell(stream);
        result.resize(size);
        rewind(stream);
        fread(result.data(), sizeof(char), size, stream);
        fclose(stream);
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