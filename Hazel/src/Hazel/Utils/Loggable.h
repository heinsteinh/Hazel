#pragma once

#include "Hazel/Core/Core.h"
#include "Hazel/Utils/format.h"

#include <ostream>

namespace Hazel
{
    class HAZEL_API Loggable
    {
    public:
        virtual ~Loggable() = default;

        virtual std::string ToString() const = 0;
    };
}

inline std::ostream &operator<<(std::ostream &stream, const Hazel::Loggable &e)
{
    return stream << e.ToString();
}

template <>
struct fmt::formatter<Hazel::Loggable &>
{
    constexpr auto parse(format_parse_context &context)
    {
        return context.begin();
    }

    template <typename FormatContext>
    constexpr auto format(const Hazel::Loggable &loggable, FormatContext &context)
    {
        return format_to(context.out(), "{}", loggable.ToString());
    }
};