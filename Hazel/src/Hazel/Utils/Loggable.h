#pragma once

#include "Hazel/Core/Core.h"
#include "spdlog/fmt/ostr.h"

namespace Hazel
{
    class HAZEL_API Loggable
    {
    public:
        virtual ~Loggable() = default;

        virtual std::string ToString() const = 0;
    };
}

inline std::ostream &operator<<(std::ostream &stream, const Hazel::Loggable &loggable)
{
    return stream << loggable.ToString();
}