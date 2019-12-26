#pragma once

#include "MouseEvent.h"

namespace Hazel
{
    class HAZEL_API MouseMovedEvent : public MouseEvent
    {
    private:
        double xPosition;
        double yPosition;

    public:
        MouseMovedEvent(double xPosition, double yPosition)
            : xPosition(xPosition),
            yPosition(yPosition)
        {
        }

        inline double GetXPosition() const
        {
            return xPosition;
        }

        inline double GetYPosition() const
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