#pragma once

#include "KeyEvent.h"
#include "Hazel/Core/Key.h"

namespace Hazel
{
    class HAZEL_API GenericKeyEvent : public KeyEvent
    {
    private:
        Key key;

    protected:
        GenericKeyEvent(Key key)
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