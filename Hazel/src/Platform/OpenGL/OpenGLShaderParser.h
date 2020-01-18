#pragma once

namespace Hazel
{
    class OpenGLShaderParser
    {
    private:
        bool failed = false;
        std::unordered_map<unsigned int, std::string> sources;

    public:
        OpenGLShaderParser() = default;

        bool Parse(const std::string &filename);

        inline bool HasFailed() const
        {
            return failed;
        }

        inline const std::unordered_map<unsigned int, std::string> &GetSources() const
        {
            return sources;
        }

        inline const std::string &GetSource(unsigned int shaderType) const
        {
            static const std::string empty;
            auto i = sources.find(shaderType);
            return i == sources.end() ? empty : sources.at(shaderType);
        }

        inline const std::string &operator[](unsigned int shaderType) const
        {
            return GetSource(shaderType);
        }

    private:
        void Reset();
        std::string ReadFile(const std::string &filename);
        void SplitShaders(const std::string &source);
    };
}