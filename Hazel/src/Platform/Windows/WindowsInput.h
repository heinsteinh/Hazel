#pragma once

#include "Hazel/Core/Input.h"
#include "GlfwKeyMap.h"

struct GLFWwindow;

namespace Hazel
{
    class WindowsInput : public Input
    {
    private:
        GLFWwindow *window = nullptr;

    public:
        WindowsInput(GLFWwindow *window);

        virtual bool IsKeyPressed(Key key) const override;
        virtual bool IsButtonPressed(MouseButton button) const override;
        virtual float GetMouseX() const override;
        virtual float GetMouseY() const override;
    };
}