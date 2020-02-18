#pragma once

namespace Hazel
{
    class FileReader
    {
    private:
        bool failed = false;

    public:
        constexpr FileReader() = default;

        inline std::string ReadAll(const std::string &filename)
        {
            FILE *stream = nullptr;
            fopen_s(&stream, filename.c_str(), "rb");
            if (!stream)
            {
                failed = true;
                return "";
            }
            failed = false;
            return ReadFile(stream);
        }

        inline bool HasFailed() const
        {
            return failed;
        }

    private:
        inline std::string ReadFile(FILE *stream)
        {
            fseek(stream, 0, SEEK_END);
            size_t size = ftell(stream);
            rewind(stream);
            std::string result;
            result.resize(size);
            fread(result.data(), sizeof(char), size, stream);
            return result;
        }
    };
}