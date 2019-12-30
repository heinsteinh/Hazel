#include "WindowsInput.h"

#include "GLFW/glfw3.h"

namespace Hazel
{
    WindowsInput::WindowsInput(GLFWwindow *window)
        : window(window)
    {
    }

    WindowsInput::~WindowsInput()
    {
    }

    bool WindowsInput::IsKeyPressed(Key key) const
    {
        return glfwGetKey(window, GlfwKeyMap::GetNativeKey(key)) == GLFW_PRESS;
    }

    bool WindowsInput::IsButtonPressed(MouseButton button) const
    {
        return glfwGetMouseButton(window, static_cast<int>(button)) == GLFW_PRESS;
    }

    double WindowsInput::GetMouseX() const
    {
        double x, y;
        glfwGetCursorPos(window, &x, &y);
        return x;
    }

    double WindowsInput::GetMouseY() const
    {
        double x, y;
        glfwGetCursorPos(window, &x, &y);
        return y;
    }
}