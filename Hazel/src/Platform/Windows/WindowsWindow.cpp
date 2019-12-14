#include "WindowsWindow.h"

#include "GLFW/glfw3.h"

#include "Hazel/Core/Logger.h"
#include "Hazel/Events/Events.h"
#include "Platform/OpenGL/OpenGLContext.h"
#include "GlfwLoader.h"

namespace Hazel
{
    Window *Window::Create()
    {
        return new WindowsWindow();
    }

    WindowsWindow::WindowsWindow()
    {
        Init();
    }

    WindowsWindow::~WindowsWindow()
    {
        Shutdown();
    }

    const std::string &WindowsWindow::GetTitle() const
    {
        return title;
    }

    int WindowsWindow::GetWidth() const
    {
        int width = 0;
        glfwGetWindowSize(window, &width, nullptr);
        return width;
    }

    int WindowsWindow::GetHeight() const
    {
        int height = 0;
        glfwGetWindowSize(window, nullptr, &height);
        return height;
    }

    bool WindowsWindow::IsVSync() const
    {
        return vsync;
    }

    void WindowsWindow::SetTitle(const std::string &title)
    {
        this->title = title;
        glfwSetWindowTitle(window, title.c_str());
    }

    void WindowsWindow::Resize(int width, int height)
    {
        CoreInfo("Window resize command: {} {}", width, height);
        glfwSetWindowSize(window, width, height);
    }

    void WindowsWindow::SetVSync(bool enabled)
    {
        CoreInfo("VSync enabled: {}", enabled);
        glfwSwapInterval(enabled ? 1 : 0);
        vsync = enabled;
    }

    void WindowsWindow::SetEventListener(EventListener *listener)
    {
        eventManager->SetEventListener(listener);
    }

    Input &WindowsWindow::GetInput() const
    {
        return *input;
    }

    void *WindowsWindow::GetNativeWindow() const
    {
        return window;
    }

    void WindowsWindow::OnUpdate()
    {
        eventManager->OnUpdate();
        context->OnUpdate();
    }

    void WindowsWindow::Init()
    {
        static const GlfwLoader loader;
        CoreInfo("Creating window");
        CreateGlfwWindow();
        CreateContext();
        CoreInfo("Window created {}", title);
    }

    void WindowsWindow::CreateGlfwWindow()
    {
        CoreDebug("GLFW window creation start {}.", title);
        window = glfwCreateWindow(defaultWidth, defaultHeight, title.c_str(), nullptr, nullptr);
        SetVSync(vsync);
        CoreDebug("GLFW window creation done {} ({}x{}).", title, GetWidth(), GetHeight());
    }

    void WindowsWindow::CreateContext()
    {
        context = std::make_unique<OpenGLContext>(window);
        input = std::make_unique<WindowsInput>(window);
        eventManager = std::make_unique<WindowsEventManager>(window);
    }

    void WindowsWindow::Shutdown()
    {
        CoreInfo("Window destruction start {}.", title);
        glfwDestroyWindow(window);
        CoreInfo("Window destruction done {}.", title);
    }
}