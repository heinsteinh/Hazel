#pragma once

#include "MouseEvent.h"

namespace Hazel
{
    class HAZEL_API MouseMovedEvent : public MouseEvent
    {
    private:
        double x;
        double y;

    public:
        MouseMovedEvent(double x, double y)
            : x(x),
            y(y)
        {
        }

        inline double GetXPosition() const
        {
            return x;
        }

        inline double GetYPosition() const
        {
            return y;
        }

        virtual std::string ToString() const override
        {
            return (std::ostringstream()
                << GetName() << ": " << x << ", " << y)
                .str();
        }
    };
}