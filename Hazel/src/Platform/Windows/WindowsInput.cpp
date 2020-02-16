#include "WindowsInput.h"

#include "GLFW/glfw3.h"

namespace Hazel
{
    WindowsInput::WindowsInput(GLFWwindow *window)
        : window(window)
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

    float WindowsInput::GetMouseX() const
    {
        double x, y;
        glfwGetCursorPos(window, &x, &y);
        return (float)x;
    }

    float WindowsInput::GetMouseY() const
    {
        double x, y;
        glfwGetCursorPos(window, &x, &y);
        return (float)y;
    }
}