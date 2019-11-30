#pragma once

#include "ApplicationEvent.h"

namespace Hazel
{
    class HAZEL_API WindowResizedEvent : public ApplicationEvent
    {
    private:
        int width;
        int height;

    public:
        WindowResizedEvent(int width, int height)
            : width(width),
            height(height)
        {
        }

        inline int GetWidth() const
        {
            return width;
        }

        inline int GetHeight() const
        {
            return height;
        }

        virtual std::string ToString() const override
        {
            return (std::ostringstream()
                << GetName() << ": " << width << ", " << height)
                .str();
        }
    };
}