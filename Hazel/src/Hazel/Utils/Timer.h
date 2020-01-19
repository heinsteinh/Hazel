#pragma once

#include "Timestep.h"

namespace Hazel
{
    class Timer
    {
    public:
        class Listener
        {
        public:
            virtual ~Listener() = default;

            virtual void OnResult(std::string_view name, Timestep duration) = 0;
        };

    private:
        std::string_view name;
        Listener *listener = nullptr;
        bool running = true;
        std::chrono::time_point<std::chrono::steady_clock> start;

    public:
        Timer(std::string_view name, Listener *listener)
            : name(name),
            listener(listener),
            start(std::chrono::high_resolution_clock::now())
        {
        }

        ~Timer()
        {
            Stop();
        }

        void Stop()
        {
            auto end = std::chrono::high_resolution_clock::now();
            if (!listener || !running)
            {
                return;
            }
            running = false;
            listener->OnResult(name, Timestep::FromMilliseconds((end - start).count() / 1000000.0f));
        }
    };
}