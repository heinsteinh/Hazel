#pragma once

#include <regex>

namespace Hazel
{
    class Regex
    {
    public:
        class Matches
        {
        private:
            std::sregex_iterator iterator;

        public:
            Matches(std::sregex_iterator iterator)
                : iterator(iterator)
            {
            }

            inline auto begin() const
            {
                return iterator;
            }

            inline auto end() const
            {
                return std::sregex_iterator();
            }
        };

    private:
        std::regex pattern;

    public:
        Regex(const std::string &pattern)
            : pattern(pattern)
        {
        }

        inline Matches FindAll(const std::string &source) const
        {
            return {{source.begin(), source.end(), pattern}};
        }
    };
}