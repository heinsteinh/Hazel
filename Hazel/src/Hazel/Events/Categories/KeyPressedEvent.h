#pragma once

#include "KeyEvent.h"

namespace Hazel
{
    class HAZEL_API KeyPressedEvent : public KeyEvent
    {
    private:
        int repeatCount;

    public:
        KeyPressedEvent(Key key, int repeatCount)
            : KeyEvent(key),
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
    };
}