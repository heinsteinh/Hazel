#pragma once

namespace Hazel
{
    class Timestep
    {
    private:
        float valueSeconds = 0.0f;

    public:
        static constexpr Timestep FromSeconds(float value)
        {
            return value;
        }

        static constexpr Timestep FromMilliseconds(float value)
        {
            return value / 1000.0f;
        }

        constexpr Timestep() = default;

        constexpr float ToSeconds() const
        {
            return valueSeconds;
        }

        constexpr float ToMilliseconds() const
        {
            return valueSeconds * 1000.0f;
        }

        constexpr Timestep operator+(const Timestep &other) const
        {
            return valueSeconds + other.valueSeconds;
        }

        constexpr Timestep operator+=(const Timestep &other)
        {
            return valueSeconds += other.valueSeconds;
        }

        constexpr Timestep operator-(const Timestep &other) const
        {
            return valueSeconds - other.valueSeconds;
        }

        constexpr Timestep operator-=(const Timestep &other)
        {
            return valueSeconds -= other.valueSeconds;
        }

        constexpr Timestep operator*(float factor) const
        {
            return valueSeconds * factor;
        }

        constexpr Timestep operator*=(float factor)
        {
            return valueSeconds *= factor;
        }

        constexpr Timestep operator/(float factor) const
        {
            return valueSeconds / factor;
        }

        constexpr Timestep operator/=(float factor)
        {
            return valueSeconds /= factor;
        }

    private:
        constexpr Timestep(float valueSeconds)
            : valueSeconds(valueSeconds)
        {
        }
    };

    constexpr Timestep operator""_s(long double value)
    {
        return Timestep::FromSeconds((float)value);
    }

    constexpr Timestep operator""_s(unsigned long long value)
    {
        return Timestep::FromSeconds((float)value);
    }

    constexpr Timestep operator""_ms(long double value)
    {
        return Timestep::FromMilliseconds((float)value);
    }

    constexpr Timestep operator""_ms(unsigned long long value)
    {
        return Timestep::FromMilliseconds((float)value);
    }
}