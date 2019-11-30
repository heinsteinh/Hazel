#pragma once

#include "Hazel/Core/Core.h"

namespace Hazel
{
    class HAZEL_API Attachable
    {
    public:
        virtual ~Attachable() = default;

        virtual void OnAttach() = 0;
        virtual void OnDetach() = 0;
    };
}