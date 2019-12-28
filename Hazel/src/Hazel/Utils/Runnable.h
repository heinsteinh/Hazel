#pragma once

#include "Hazel/Core/Core.h"
#include "Hazel/Core/Timestep.h"

namespace Hazel
{
    class HAZEL_API Runnable
    {
    public:
        virtual ~Runnable() = default;

        virtual void OnUpdate(Timestep deltaTime) = 0;
    };
}