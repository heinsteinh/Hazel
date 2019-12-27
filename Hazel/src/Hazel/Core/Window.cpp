#include "Window.h"

#include "Platform/Windows/WindowsWindow.h"

namespace Hazel
{
    Window *Window::Create(const RenderApi &api)
    {
#ifdef _WIN64
        return new WindowsWindow(api);
#else
        return nullptr;
#endif
    }
}