#include "WindowsPlatform.h"

#include "GLFW/glfw3.h"

#include "WindowsWindow.h"

namespace Hazel
{
    Window *WindowsPlatform::CreateNewWindow(RenderApi &api)
    {
        return new WindowsWindow(api);
    }

    double WindowsPlatform::GetTime()
    {
        return glfwGetTime();
    }
}