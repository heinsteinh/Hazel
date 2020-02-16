#include "WindowsWindow.h"

#include "GLFW/glfw3.h"

#include "Hazel/Events/Events.h"
#include "GlfwLoader.h"

namespace Hazel
{
    WindowsWindow::WindowsWindow(RenderApi &api)
    {
        Init(api);
    }

    WindowsWindow::~WindowsWindow()
    {
        Shutdown();
    }

    Context &WindowsWindow::GetContext() const
    {
        return *context;
    }

    const std::string &WindowsWindow::GetTitle() const
    {
        return title;
    }

    float WindowsWindow::GetWidth() const
    {
        int width = 0;
        glfwGetWindowSize(window, &width, nullptr);
        return (float)width;
    }

    float WindowsWindow::GetHeight() const
    {
        int height = 0;
        glfwGetWindowSize(window, nullptr, &height);
        return (float)height;
    }

    bool WindowsWindow::HasVerticalSynchronization() const
    {
        return verticalSynchronization;
    }

    void WindowsWindow::SetTitle(const std::string &title)
    {
        CoreInfo("Window title set to {}.", title);
        this->title = title;
        glfwSetWindowTitle(window, title.c_str());
    }

    void WindowsWindow::Resize(float width, float height)
    {
        CoreDebug("Window resized to ({}, {})", width, height);
        glfwSetWindowSize(window, (int)width, (int)height);
    }

    void WindowsWindow::SetVerticalSynchronization(bool enabled)
    {
        CoreInfo("VSync enabled {}", enabled);
        glfwSwapInterval(enabled ? 1 : 0);
        verticalSynchronization = enabled;
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

    void WindowsWindow::OnUpdate(Timestep deltaTime)
    {
        eventManager->PollEvents();
        context->GetDrawer().SwapBuffers();
    }

    void WindowsWindow::Init(RenderApi &api)
    {
        static GlfwLoader loader;
        CoreInfo("Creating window");
        CreateGlfwWindow(api);
        SetVerticalSynchronization(verticalSynchronization);
        CoreInfo("Window created {} ({}x{}).", title, GetWidth(), GetHeight());
    }

    void WindowsWindow::CreateGlfwWindow(RenderApi &api)
    {
        CoreDebug("GLFW window creation start.");
        window = glfwCreateWindow(1280, 720, title.c_str(), nullptr, nullptr);
        context.reset(api.CreateContext(*this));
        input = MakeUnique<WindowsInput>(window);
        eventManager = MakeUnique<WindowsEventManager>(window);
        CoreDebug("GLFW window creation done.");
    }

    void WindowsWindow::Shutdown()
    {
        CoreDebug("Window {} destruction.", title);
        glfwDestroyWindow(window);
    }
}