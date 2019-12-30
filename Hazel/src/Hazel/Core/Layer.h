#pragma once

#include "Hazel/Events/Events.h"
#include "Hazel/Utils/Attachable.h"
#include "Hazel/Utils/Runnable.h"

namespace Hazel
{
    class HAZEL_API Layer : public EventListener, public Attachable, public Runnable
    {
    public:
        virtual ~Layer() = default;

        virtual void OnImGuiRender() = 0;
    };
}