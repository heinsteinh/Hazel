#pragma once

#include "Hazel/Core/Core.h"

namespace Hazel
{
    template<typename T>
    class HAZEL_API Reversed
    {
    private:
        T &iterable;

    public:
        Reversed(T &iterable)
            : iterable(iterable)
        {
        }

        inline auto begin()
        {
            return iterable.rbegin();
        }

        inline auto end()
        {
            return iterable.rend();
        }
    };
}