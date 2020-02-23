#pragma once

#include "Timestep.h"

namespace Hazel
{
    class HAZEL_API Updatable
    {
    public:
        virtual ~Updatable() = default;

        virtual void OnUpdate(Timestep deltaTime) = 0;
    };
}