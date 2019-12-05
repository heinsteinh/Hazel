#include "WindowsInput.h"

namespace Hazel
{
    WindowsInput::WindowsInput(GLFWwindow *window)
        : window(window)
    {
    }

    WindowsInput::~WindowsInput()
    {
    }

    bool WindowsInput::IsKeyPressed(Key key)
    {
        int state = glfwGetKey(window, GlfwKeyMap::GetNativeKey(key));
        return state == GLFW_PRESS || state == GLFW_REPEAT;
    }

    bool WindowsInput::IsButtonPressed(MouseButton button)
    {
        return glfwGetMouseButton(window, static_cast<int>(button)) == GLFW_PRESS;
    }

    double WindowsInput::GetMouseX()
    {
        double x, y;
        glfwGetCursorPos(window, &x, &y);
        return x;
    }

    double WindowsInput::GetMouseY()
    {
        double x, y;
        glfwGetCursorPos(window, &x, &y);
        return y;
    }
}