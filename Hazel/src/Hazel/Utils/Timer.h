#pragma once

#include "TimerListener.h"

namespace Hazel
{
    class Timer
    {
    private:
        const std::string &name;
        TimerListener *listener = nullptr;
        std::chrono::time_point<std::chrono::steady_clock> start;

    public:
        Timer(const std::string &name, TimerListener *listener)
            : name(name),
            listener(listener),
            start(std::chrono::high_resolution_clock::now())
        {
        }

        ~Timer()
        {
            Stop();
        }

        inline void Stop()
        {
            auto end = std::chrono::high_resolution_clock::now();
            if (listener)
            {
                listener->OnMeasurement(name, GetDuration(end - start));
                listener = nullptr;
            }
        }

    private:
        constexpr Timestep GetDuration(std::chrono::nanoseconds duration) const
        {
            return Timestep::FromSeconds(
                std::chrono::duration_cast<std::chrono::duration<float>>(duration)
                .count());
        }
    };
}