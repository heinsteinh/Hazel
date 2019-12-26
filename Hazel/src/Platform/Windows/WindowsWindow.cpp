#include "WindowsWindow.h"

#include "GLFW/glfw3.h"

#include "Hazel/Core/Log.h"
#include "Hazel/Events/Events.h"
#include "Hazel/Renderer/Renderer.h"
#include "GlfwLoader.h"

namespace Hazel
{
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
        CoreInfo("Window title changed to {}.", title);
        this->title = title;
        glfwSetWindowTitle(window, title.c_str());
    }

    void WindowsWindow::Resize(int width, int height)
    {
        CoreDebug("Window resized from code: {} {}", width, height);
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
        static GlfwLoader loader;
        CoreInfo("Creating window");
        CreateGlfwWindow();
        CreateContext();
        SetVSync(vsync);
        CoreInfo("Window created {} ({}x{}).", title, GetWidth(), GetHeight());
    }

    void WindowsWindow::CreateGlfwWindow()
    {
        CoreDebug("GLFW window creation start.");
        window = glfwCreateWindow(defaultWidth, defaultHeight, title.c_str(), nullptr, nullptr);
        CoreDebug("GLFW window creation done.");
    }

    void WindowsWindow::CreateContext()
    {
        CoreDebug("Creating context for rendering, inputs and events.");
        context.reset(Renderer::CreateContext(*this));
        input = std::make_unique<WindowsInput>(window);
        eventManager = std::make_unique<WindowsEventManager>(window);
        CoreDebug("Context created.");
    }

    void WindowsWindow::Shutdown()
    {
        CoreInfo("Window {} destruction.", title);
        glfwDestroyWindow(window);
        CoreInfo("Window {} destruction done.", title);
    }
}