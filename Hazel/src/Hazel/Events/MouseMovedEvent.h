#pragma once

#include "MouseEvent.h"

namespace Hazel
{
    class HAZEL_API MouseMovedEvent : public MouseEvent
    {
    private:
        float xPosition;
        float yPosition;

    public:
        constexpr MouseMovedEvent(float xPosition, float yPosition)
            : xPosition(xPosition),
            yPosition(yPosition)
        {
        }

        inline float GetXPosition() const
        {
            return xPosition;
        }

        inline float GetYPosition() const
        {
            return yPosition;
        }

        virtual std::string ToString() const override
        {
            return (std::ostringstream()
                << GetName() << ": " << xPosition << ", " << yPosition)
                .str();
        }

    protected:
        virtual void Handle(EventListener &listener) override
        {
            listener.OnMouseMoved(*this);
        }
    };
}