#pragma once

#include "MouseEvent.h"

namespace Hazel
{
    class HAZEL_API MouseScrolledEvent : public MouseEvent
    {
    private:
        double xOffset;
        double yOffset;

    public:
        MouseScrolledEvent(double xOffset, double yOffset)
            : xOffset(xOffset),
            yOffset(yOffset)
        {
        }

        inline double GetXOffset() const
        {
            return xOffset;
        }

        inline double GetYOffset() const
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