#pragma once

#include "ApplicationEvent.h"

namespace Hazel
{
    class HAZEL_API WindowResizedEvent : public ApplicationEvent
    {
    private:
        float width;
        float height;

    public:
        constexpr WindowResizedEvent(float width, float height)
            : width(width),
            height(height)
        {
        }

        inline float GetWidth() const
        {
            return width;
        }

        inline float GetHeight() const
        {
            return height;
        }

        virtual std::string ToString() const override
        {
            return (std::ostringstream()
                << GetName() << ": " << width << ", " << height)
                .str();
        }

    protected:
        virtual void Handle(EventListener &listener) override
        {
            listener.OnApplicationEvent(*this);
            listener.OnWindowResized(*this);
        }
    };
}