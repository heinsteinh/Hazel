#pragma once

#include "KeyEvent.h"
#include "Hazel/Core/Key.h"

namespace Hazel
{
    class HAZEL_API GenericKeyEvent : public KeyEvent
    {
    private:
        Key key;

    public:
        constexpr GenericKeyEvent(Key key)
            : key(key)
        {
        }

        inline Key GetKey() const
        {
            return key;
        }

        virtual std::string ToString() const override
        {
            return (std::ostringstream()
                << GetName() << ": " << static_cast<int>(key))
                .str();
        }
    };
}