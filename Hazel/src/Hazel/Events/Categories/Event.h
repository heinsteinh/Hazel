#pragma once

#include "Hazel/Core/Core.h"
#include "Hazel/Utils/Loggable.h"

#include <string>
#include <sstream>

namespace Hazel
{
    class HAZEL_API Event : public Loggable
    {
    private:
        bool handled = false;

    protected:
        Event() = default;

    public:
        Event(const Event &other) = delete;
        virtual ~Event() = default;

        Event &operator=(const Event &other) = delete;

        inline const char *GetName() const
        {
            return typeid(*this).name() + 13;
        }

        inline bool IsHandled() const
        {
            return handled;
        }

        inline void SetHandled()
        {
            handled = true;
        }

        virtual std::string ToString() const override
        {
            return GetName();
        }
    };
}