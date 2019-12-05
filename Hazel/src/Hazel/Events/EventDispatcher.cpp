#include "EventDispatcher.h"

#include <unordered_map>

#define MAP(type) {typeid(##type).hash_code(), &EventDispatcher::Dispatch##type}

namespace Hazel
{
    EventDispatcher::EventDispatcher(EventListener *listener)
        : listener(listener)
    {
    }

    void EventDispatcher::SetListener(EventListener *listener)
    {
        this->listener = listener;
    }

    void EventDispatcher::Dispatch(Event &e)
    {
        static const std::unordered_map<size_t, bool (EventDispatcher:: *)(Event &)> methods = {
            MAP(WindowClosedEvent),
            MAP(WindowResizedEvent),
            MAP(MouseButtonPressedEvent),
            MAP(MouseButtonReleasedEvent),
            MAP(MouseMovedEvent),
            MAP(MouseScrolledEvent),
            MAP(KeyPressedEvent),
            MAP(KeyReleasedEvent),
            MAP(KeyTypedEvent),
        };
        if (listener && !e.IsHandled())
        {
            (this->*(methods.at(typeid(e).hash_code())))(e);
        }
    }
}

#undef MAP