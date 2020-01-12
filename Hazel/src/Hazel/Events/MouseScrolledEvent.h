#pragma once

#include "MouseEvent.h"

namespace Hazel
{
    class HAZEL_API MouseScrolledEvent : public MouseEvent
    {
    private:
        float xOffset;
        float yOffset;

    public:
        constexpr MouseScrolledEvent(float xOffset, float yOffset)
            : xOffset(xOffset),
            yOffset(yOffset)
        {
        }

        inline float GetXOffset() const
        {
            return xOffset;
        }

        inline float GetYOffset() const
        {
            return yOffset;
        }

        virtual std::string ToString() const override
        {
            return (std::ostringstream()
                << GetName() << ": " << xOffset << ", " << yOffset)
                .str();
        }

    protected:
        virtual void Handle(EventListener &listener) override
        {
            listener.OnMouseScrolled(*this);
        }
    };
}