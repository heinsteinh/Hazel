#pragma once

#include "GenericKeyEvent.h"

namespace Hazel
{
    class HAZEL_API KeyPressedEvent : public GenericKeyEvent
    {
    private:
        int repeatCount;

    public:
        constexpr KeyPressedEvent(Key key, int repeatCount)
            : GenericKeyEvent(key),
            repeatCount(repeatCount)
        {
        }

        inline int GetRepeatCount() const
        {
            return repeatCount;
        }

        virtual std::string ToString() const override
        {
            return (std::ostringstream()
                << GetName() << ": " << static_cast<int>(GetKey())
                << " (" << repeatCount << " repeats)")
                .str();
        }

    protected:
        virtual void Handle(EventListener &listener) override
        {
            listener.OnInputEvent(*this);
            listener.OnKeyEvent(*this);
            listener.OnKeyPressed(*this);
        }
    };
}