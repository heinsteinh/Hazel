#pragma once

#include "Hazel/Core/Core.h"
#include "spdlog/fmt/ostr.h"

namespace Hazel
{
    class HAZEL_API Printable
    {
    public:
        virtual ~Printable() = default;

        virtual std::string ToString() const = 0;
    };
}

inline std::ostream &operator<<(std::ostream &stream, const Hazel::Printable &printable)
{
    return stream << printable.ToString();
}