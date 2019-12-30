#pragma once

#include <sstream>

#include "spdlog/fmt/ostr.h"

#include "Hazel/Core/Core.h"
#include "EventListener.h"

namespace Hazel
{
    class HAZEL_API Event
    {
    private:
        bool handled = false;

    public:
        constexpr Event() = default;
        virtual ~Event() = default;

        Event(const Event &other) = delete;
        Event &operator=(const Event &other) = delete;

        inline const char *GetName() const
        {
            return typeid(*this).name() + 13;
        }

        inline bool IsHandled() const
        {
            return handled;
        }

        inline void Discard()
        {
            handled = true;
        }

        inline void Dispatch(EventListener *listener)
        {
            if (listener && !handled)
            {
                listener->OnEvent(*this);
                Handle(*listener);
            }
        }

        virtual std::string ToString() const
        {
            return GetName();
        }

    protected:
        virtual void Handle(EventListener &listener) = 0;
    };
}

inline std::ostream &operator<<(std::ostream &stream, const Hazel::Event &e)
{
    return stream << e.ToString();
}