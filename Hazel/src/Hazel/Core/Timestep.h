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
    };
}