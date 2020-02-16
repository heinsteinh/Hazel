#pragma once

namespace Hazel
{
    class FileInfo
    {
    private:
        const std::string &filename;

    public:
        constexpr FileInfo(const std::string &filename)
            : filename(filename)
        {
        }

        inline std::string GetDirectory() const
        {
            size_t offset = filename.find_last_of("/\\");
            return offset == std::string::npos ? "" : filename.substr(0, offset);
        }

        inline std::string GetBaseName() const
        {
            size_t start = filename.find_last_of("/\\");
            start = start == std::string::npos ? 0 : start + 1;
            size_t end = filename.rfind('.');
            end = end == std::string::npos ? filename.size() : end;
            return filename.substr(start, (end > start ? end : filename.size()) - start);
        }

        inline std::string GetExtension() const
        {
            size_t offset = filename.find('.');
            return offset == std::string::npos
                ? ""
                : filename.substr(offset + 1, filename.size() - offset);
        }
    };
}