#pragma once

#include "EventListener.h"

namespace Hazel
{
    class HAZEL_API ApplicationListener : public virtual EventListener
    {
    public:
        virtual ~ApplicationListener() = default;

        virtual void OnApplicationEvent(ApplicationEvent &e) = 0;
    };
}