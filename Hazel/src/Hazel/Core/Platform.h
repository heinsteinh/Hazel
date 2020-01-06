#pragma once

#include "Window.h"
#include "Hazel/Rendering/RenderApi.h"

namespace Hazel
{
    class HAZEL_API Platform
    {
    public:
        static Platform &Get();

        virtual ~Platform() = default;

        virtual Window *CreateNewWindow(RenderApi &api = RenderApi::OpenGL) = 0;
        virtual double GetTime() = 0;
    };
}