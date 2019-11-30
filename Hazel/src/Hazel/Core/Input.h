#pragma once

#include "Core.h"
#include "Hazel/Core/Key.h"
#include "Hazel/Core/MouseButton.h"

namespace Hazel
{
    class HAZEL_API Input
    {
    public:
        virtual ~Input() = default;

        virtual bool IsKeyPressed(Key key) = 0;
        virtual bool IsButtonPressed(MouseButton button) = 0;
        virtual double GetMouseX() = 0;
        virtual double GetMouseY() = 0;
    };
}