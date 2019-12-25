#include "EventDispatcher.h"

#include <unordered_map>
#include <functional>

namespace Hazel
{
    using EventCallback = std::function<void(EventListener *, Event &)>;

    template<typename T, void(EventListener:: * M)(T &)>
    static void DispatchEvent(EventListener *listener, Event &e)
    {
        (listener->*M)((T &)e);
    }

#define MAP(type, method) {typeid(type).hash_code(), &DispatchEvent<type, &EventListener::method>}
    static const std::unordered_map<size_t, EventCallback> callbacks = {
        MAP(WindowClosedEvent, OnWindowClosed),
        MAP(WindowResizedEvent, OnWindowResized),
        MAP(KeyTypedEvent, OnKeyTyped),
        MAP(KeyPressedEvent, OnKeyPressed),
        MAP(KeyReleasedEvent, OnKeyReleased),
        MAP(MouseMovedEvent, OnMouseMoved),
        MAP(MouseScrolledEvent, OnMouseScrolled),
        MAP(MouseButtonPressedEvent, OnMouseButtonPressed),
        MAP(MouseButtonReleasedEvent, OnMouseButtonReleased)
    };
#undef MAP

    EventDispatcher::EventDispatcher(EventListener *listener)
        : listener(listener)
    {
    }

    void EventDispatcher::SetEventListener(EventListener *listener)
    {
        this->listener = listener;
    }

    void EventDispatcher::Dispatch(Event &e)
    {
        if (!listener || e.IsHandled())
        {
            return;
        }
        auto typeAndCallback = callbacks.find(typeid(e).hash_code());
        if (typeAndCallback != callbacks.end())
        {
            typeAndCallback->second(listener, e);
        }
    }
}