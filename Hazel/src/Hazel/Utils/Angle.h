#pragma once

#include "glm/glm.hpp"

namespace Hazel
{
    class Angle
    {
    private:
        float radians = 0.0f;

    public:
        static constexpr Angle FromRadians(float value)
        {
            return value;
        }

        static constexpr Angle FromDegrees(float value)
        {
            return glm::radians(value);
        }

        constexpr Angle() = default;

        constexpr float ToRadians() const
        {
            return radians;
        }

        constexpr float ToDegrees() const
        {
            return FromRadians(radians).ToDegrees();
        }

        constexpr operator bool() const
        {
            return radians;
        }

        constexpr bool operator==(const Angle &other) const
        {
            return radians == other.radians;
        }

        constexpr bool operator!=(const Angle &other) const
        {
            return radians != other.radians;
        }

        constexpr Angle operator+(const Angle &other) const
        {
            return radians + other.radians;
        }

        constexpr Angle operator+=(const Angle &other)
        {
            return radians += other.radians;
        }

        constexpr Angle operator-(const Angle &other) const
        {
            return radians - other.radians;
        }

        constexpr Angle operator-=(const Angle &other)
        {
            return radians -= other.radians;
        }

        constexpr Angle operator*(float factor) const
        {
            return radians * factor;
        }

        constexpr Angle operator*=(float factor)
        {
            return radians *= factor;
        }

        constexpr Angle operator/(float factor) const
        {
            return radians / factor;
        }

        constexpr Angle operator/=(float factor)
        {
            return radians /= factor;
        }

    private:
        constexpr Angle(float radians)
            : radians(radians)
        {
        }
    };

    constexpr Angle operator""_rad(long double value)
    {
        return Angle::FromRadians(static_cast<float>(value));
    }

    constexpr Angle operator""_rad(unsigned long long value)
    {
        return Angle::FromRadians(static_cast<float>(value));
    }

    constexpr Angle operator""_deg(long double value)
    {
        return Angle::FromDegrees(static_cast<float>(value));
    }

    constexpr Angle operator""_deg(unsigned long long value)
    {
        return Angle::FromDegrees(static_cast<float>(value));
    }
}