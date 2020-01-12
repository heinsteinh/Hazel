#pragma once

#include "glm/glm.hpp"

namespace Hazel
{
    class Angle
    {
    private:
        float valueRadians = 0.0f;

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
            return valueRadians;
        }

        constexpr float ToDegrees() const
        {
            return FromRadians(valueRadians).ToDegrees();
        }

        constexpr Angle operator+(const Angle &other) const
        {
            return valueRadians + other.valueRadians;
        }

        constexpr Angle operator+=(const Angle &other)
        {
            return valueRadians += other.valueRadians;
        }

        constexpr Angle operator-(const Angle &other) const
        {
            return valueRadians - other.valueRadians;
        }

        constexpr Angle operator-=(const Angle &other)
        {
            return valueRadians -= other.valueRadians;
        }

        constexpr Angle operator*(float factor) const
        {
            return valueRadians * factor;
        }

        constexpr Angle operator*=(float factor)
        {
            return valueRadians *= factor;
        }

        constexpr Angle operator/(float factor) const
        {
            return valueRadians / factor;
        }

        constexpr Angle operator/=(float factor)
        {
            return valueRadians /= factor;
        }

    private:
        constexpr Angle(float valueRadians)
            : valueRadians(valueRadians)
        {
        }
    };

    constexpr Angle operator""_rad(long double value)
    {
        return Angle::FromRadians((float)value);
    }

    constexpr Angle operator""_rad(unsigned long long value)
    {
        return Angle::FromRadians((float)value);
    }

    constexpr Angle operator""_deg(long double value)
    {
        return Angle::FromDegrees((float)value);
    }

    constexpr Angle operator""_deg(unsigned long long value)
    {
        return Angle::FromDegrees((float)value);
    }
}