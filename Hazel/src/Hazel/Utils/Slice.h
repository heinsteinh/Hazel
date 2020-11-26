#pragma once

namespace Hazel
{
    template<typename T>
    class Slice
    {
    private:
        T &iterable;
        size_t start = 0;
        size_t end = -1;

    public:
        constexpr Slice(T &iterable, size_t start = 0, size_t end = -1)
            : iterable(iterable),
            start(start),
            end(end)
        {
        }

        auto begin()
        {
            return iterable.begin() + start;
        }

        auto end()
        {
            return end < start ? iterable.end() : iterable.begin() + end;
        }
    };
}