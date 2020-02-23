#pragma once

#include "Hazel/Events/Events.h"
#include "Hazel/Utils/Attachable.h"
#include "Hazel/Utils/Updatable.h"

namespace Hazel
{
    class HAZEL_API Layer : public EventListener, public Attachable, public Updatable
    {
    public:
        virtual ~Layer() = default;

        virtual void OnImGuiRender() = 0;
    };
}