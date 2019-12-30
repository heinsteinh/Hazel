#pragma once

#include <memory>

namespace Hazel
{
    template<typename T>
    using UniquePtr = std::unique_ptr<T>;
}