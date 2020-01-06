#include "WindowsWindow.h"

#include "GLFW/glfw3.h"

#include "Hazel/Core/Log.h"
#include "Hazel/Events/Events.h"
#include "Hazel/Rendering/Renderer.h"
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
        return *context.get();
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

    int WindowsWindow::GetFrameBufferWidth() const
    {
        int width = 0;
        glfwGetFramebufferSize(window, &width, nullptr);
        return width;
    }

    int WindowsWindow::GetFrameBufferHeight() const
    {
        int height = 0;
        glfwGetFramebufferSize(window, nullptr, &height);
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
        SetVSync(vsync);
        CoreInfo("Window created {} ({}x{}).", title, GetWidth(), GetHeight());
    }

    void WindowsWindow::CreateGlfwWindow(RenderApi &api)
    {
        CoreDebug("GLFW window creation start.");
        window = glfwCreateWindow(1280, 720, title.c_str(), nullptr, nullptr);
        context.reset(api.CreateContext(*this));
        input = std::make_unique<WindowsInput>(window);
        eventManager = std::make_unique<WindowsEventManager>(window);
        CoreDebug("GLFW window creation done.");
    }

    void WindowsWindow::Shutdown()
    {
        CoreDebug("Window {} destruction.", title);
        glfwDestroyWindow(window);
    }
}