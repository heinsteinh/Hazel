#pragma once

#include <memory>

namespace Hazel
{
    template<typename T>
    using SharedPtr = std::shared_ptr<T>;

    template<typename T, typename ...Args>
    constexpr auto MakeShared(Args &&...args)
    {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }
}