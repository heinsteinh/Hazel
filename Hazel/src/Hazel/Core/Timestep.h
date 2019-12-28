#pragma once

namespace Hazel
{
    class Timestep
    {
    private:
        double time = 0.0;

    public:
        constexpr Timestep(double time)
            : time(time)
        {
        }

        inline double GetSeconds() const
        {
            return time;
        }

        inline double GetMilliseconds() const
        {
            return 1000 * time;
        }

        inline operator float() const
        {
            return (float)time;
        }

        inline Timestep operator+(double delta) const
        {
            return time + delta;
        }

        inline Timestep operator-(double delta) const
        {
            return time - delta;
        }

        inline Timestep operator*(double factor) const
        {
            return time * factor;
        }

        inline Timestep operator/(double factor) const
        {
            return time / factor;
        }
    };
}