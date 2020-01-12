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
        virtual float GetMouseX() const = 0;
        virtual float GetMouseY() const = 0;
    };
}