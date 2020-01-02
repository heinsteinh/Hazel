#pragma once

#include <regex>

namespace Hazel
{
    class Regex
    {
    public:
        class AllMatches
        {
        private:
            const std::string &source;
            const std::regex &pattern;

        public:
            constexpr AllMatches(const std::string &source, const std::regex &pattern)
                : source(source),
                pattern(pattern)
            {
            }

            inline auto begin() const
            {
                return std::sregex_iterator(source.begin(), source.end(), pattern);
            }

            inline const auto &end() const
            {
                static const std::sregex_iterator result;
                return result;
            }
        };

    private:
        std::regex pattern;

    public:
        Regex(const char *pattern)
            : pattern(pattern)
        {
        }

        inline AllMatches Search(const std::string &source) const
        {
            return AllMatches(source, pattern);
        }
    };
}