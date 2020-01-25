#pragma once

#include "Timestep.h"

namespace Hazel
{
    class TimerListener
    {
    public:
        virtual ~TimerListener() = default;

        virtual void OnMeasurement(const std::string &name, Timestep duration) = 0;
    };
}