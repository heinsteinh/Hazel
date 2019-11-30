#pragma once

#include "InputEvent.h"
#include "Hazel/Core/Key.h"

namespace Hazel
{
    class HAZEL_API KeyEvent : public InputEvent
    {
    private:
        Key key;

    protected:
        KeyEvent(Key key)
            : key(key)
        {
        }

    public:
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