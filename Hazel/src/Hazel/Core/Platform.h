#pragma once

#include "Window.h"
#include "Hazel/Rendering/Drawing/RenderApi.h"

namespace Hazel
{
    class HAZEL_API Platform
    {
    public:
        static Platform &Get();

        virtual ~Platform() = default;

        virtual Window *CreateNewWindow(RenderApi &api) = 0;
        virtual double GetTime() = 0;
    };
}