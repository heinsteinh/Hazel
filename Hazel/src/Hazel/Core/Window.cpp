#include "Window.h"

#include "Platform/Windows/WindowsWindow.h"

namespace Hazel
{
    Window *Window::Create()
    {
#ifdef _WIN64
        return new WindowsWindow();
#else
        return nullptr;
#endif
    }
}