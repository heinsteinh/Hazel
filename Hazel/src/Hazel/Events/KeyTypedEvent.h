#pragma once

#include "KeyEvent.h"

namespace Hazel
{
    class HAZEL_API KeyTypedEvent : public KeyEvent
    {
    private:
        int key;

    public:
        KeyTypedEvent(int key)
            : key(key)
        {
        }

        inline int GetKey() const
        {
            return key;
        }

        virtual std::string ToString() const override
        {
            return (std::ostringstream()
                << GetName() << ": " << key)
                .str();
        }

    protected:
        virtual void Handle(EventListener &listener) override
        {
            listener.OnKeyTyped(*this);
        }
    };
}