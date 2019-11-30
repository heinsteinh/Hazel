#pragma once

#include "Hazel/Core/Input.h"
#include "GlfwKeyMap.h"
#include "GLFW/glfw3.h"
#include "glad/glad.h"

namespace Hazel
{
    class WindowsInput : public Input
    {
    private:
        GLFWwindow *window = nullptr;

    public:
        WindowsInput(GLFWwindow *window);
        virtual ~WindowsInput();

        virtual bool IsKeyPressed(Key key) override;
        virtual bool IsButtonPressed(MouseButton button) override;
        virtual double GetMouseX() override;
        virtual double GetMouseY() override;
    };
}