#pragma once

#include "Hazel/Core/Core.h"
#include "Categories/Categories.h"
#include "EventListener.h"

namespace Hazel
{
    class HAZEL_API EventDispatcher
    {
    private:
        EventListener *listener;

    public:
        EventDispatcher(EventListener *listener = nullptr);

        void SetEventListener(EventListener *listener);
        void Dispatch(Event &e);
    };
}