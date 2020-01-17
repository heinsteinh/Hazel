#pragma once

#include <memory>

namespace Hazel
{
    template<typename T>
    using UniquePtr = std::unique_ptr<T>;

    template<typename T, typename ...Args>
    constexpr auto MakeUnique(Args &&...args)
    {
        return std::make_unique<T>(args...);
    }
}