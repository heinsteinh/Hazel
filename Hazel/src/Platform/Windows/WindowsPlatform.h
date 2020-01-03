#pragma once

#include "Hazel/Core/Platform.h"

namespace Hazel
{
    class WindowsPlatform : public Platform
    {
    public:
        virtual ~WindowsPlatform() = default;

        virtual Window *CreateNewWindow(RenderApi &api = RenderApi::OpenGL) override;
        virtual double GetTime() override;
    };
}