#pragma once

#include "Hazel/Core/Key.h"
#include "Hazel/Core/MouseButton.h"

namespace Hazel
{
    class HAZEL_API Input
    {
    public:
        virtual ~Input() = default;

        virtual bool IsKeyPressed(Key key) const = 0;
        virtual bool IsButtonPressed(MouseButton button) const = 0;
        virtual double GetMouseX() const = 0;
        virtual double GetMouseY() const = 0;
    };
}