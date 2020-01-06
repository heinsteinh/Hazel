#pragma once

#include <memory>

namespace Hazel
{
    template<typename T>
    using SharedPtr = std::shared_ptr<T>;
}