#pragma once

#include "MouseEvent.h"
#include "Hazel/Core/MouseButton.h"

namespace Hazel
{
    class HAZEL_API MouseButtonEvent : public MouseEvent
    {
    private:
        MouseButton button;

    public:
        MouseButtonEvent(MouseButton button)
            : button(button)
        {
        }

        inline MouseButton GetButton() const
        {
            return button;
        }

        virtual std::string ToString() const override
        {
            return (std::ostringstream()
                << GetName() << ": " << static_cast<int>(button))
                .str();
        }
    };
}