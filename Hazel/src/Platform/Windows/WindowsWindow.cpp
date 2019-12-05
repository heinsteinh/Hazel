#include "WindowsWindow.h"

#include "Hazel/Core/Logger.h"
#include "Hazel/Events/Events.h"

namespace Hazel
{
    Window *Window::Create()
    {
        return new WindowsWindow();
    }

    bool WindowsWindow::glfwInitialized = false;

    WindowsWindow::WindowsWindow()
    {
        Init();
    }

    WindowsWindow::~WindowsWindow()
    {
        Shutdown();
    }

    void WindowsWindow::OnUpdate()
    {
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    const std::string &WindowsWindow::GetTitle() const
    {
        return title;
    }

    int WindowsWindow::GetWidth() const
    {
        return width;
    }

    int WindowsWindow::GetHeight() const
    {
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
        dispatcher.SetListener(listener);
    }

    Input &WindowsWindow::GetInput() const
    {
        return *input;
    }

    void *WindowsWindow::GetNativeWindow() const
    {
        return window;
    }

    WindowsWindow &WindowsWindow::GetWindow(GLFWwindow *window)
    {
        return *(WindowsWindow *)glfwGetWindowUserPointer(window);
    }

    void WindowsWindow::OnError(int error, const char *description)
    {
        CoreError("GLFW Error {}: {}", error, description);
    }

    void WindowsWindow::Init()
    {
        CoreInfo("Creating window");
        InitGlfwIfNotDone();
        CreateGlfwWindow();
        InitGladIfNotDone();
        SetupCallbacks();
        glfwInitialized = true;
        CoreInfo("Window created {} ({}x{})", title, width, height);
    }

    void WindowsWindow::InitGlfwIfNotDone()
    {
        CoreTrace("GLFW initialization.");
        if (glfwInitialized)
        {
            CoreTrace("Already done");
            return;
        }
        if (!glfwInit())
        {
            CoreError("GLFW cannot be initialized.");
        }
        glfwSetErrorCallback(WindowsWindow::OnError);
        CoreTrace("GLFW initialized.");
    }

    void WindowsWindow::CreateGlfwWindow()
    {
        CoreTrace("GLFW window creation start {} ({}x{}).", title, width, height);
        window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
        input = new WindowsInput(window);
        glfwMakeContextCurrent(window);
        glfwSetWindowUserPointer(window, this);
        SetVSync(vsync);
        CoreTrace("GLFW window creation done {} ({}x{}).", title, width, height);
    }

    void WindowsWindow::InitGladIfNotDone()
    {
        CoreTrace("Glad initialization.");
        if (glfwInitialized)
        {
            CoreTrace("Already done");
            return;
        }
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            throw std::exception("Glad cannot be initialized.");
        }
        CoreTrace("Glad initialized.");
    }

    void WindowsWindow::SetupCallbacks()
    {
        CoreTrace("Callback setup.");
        SetupWindowCallbacks();
        SetupKeyCallbacks();
        SetupMouseCallbacks();
        CoreTrace("Callback setup OK.");
    }

    void WindowsWindow::SetupWindowCallbacks()
    {
        glfwSetWindowSizeCallback(window, [](GLFWwindow *window, int width, int height)
        {
            GetWindow(window).OnResize(width, height);
        });
        glfwSetWindowCloseCallback(window, [](GLFWwindow *window)
        {
            GetWindow(window).OnClose();
        });
    }

    void WindowsWindow::SetupKeyCallbacks()
    {
        glfwSetKeyCallback(window, [](GLFWwindow *window, int key, int scancode, int action, int mods)
        {
            GetWindow(window).OnKey(key, action);
        });
        glfwSetCharCallback(window, [](GLFWwindow *window, unsigned int key)
        {
            GetWindow(window).OnChar(key);
        });
    }

    void WindowsWindow::SetupMouseCallbacks()
    {
        glfwSetMouseButtonCallback(window, [](GLFWwindow *window, int button, int action, int mods)
        {
            GetWindow(window).OnMouseButton(button, action);
        });
        glfwSetScrollCallback(window, [](GLFWwindow *window, double x, double y)
        {
            GetWindow(window).OnMouseScrolled(x, y);
        });
        glfwSetCursorPosCallback(window, [](GLFWwindow *window, double x, double y)
        {
            GetWindow(window).OnMouseMoved(x, y);
        });
    }

    void WindowsWindow::OnResize(int width, int height)
    {
        this->width = width;
        this->height = height;
        dispatcher.Dispatch(WindowResizedEvent(width, height));
    }

    void WindowsWindow::OnClose()
    {
        dispatcher.Dispatch(WindowClosedEvent());
    }

    void WindowsWindow::OnKey(int key, int action)
    {
        switch (action)
        {
        case GLFW_PRESS:
            dispatcher.Dispatch(KeyPressedEvent(GlfwKeyMap::GetHazelKey(key), 0));
            count = 0;
            break;
        case GLFW_RELEASE:
            dispatcher.Dispatch(KeyReleasedEvent(GlfwKeyMap::GetHazelKey(key)));
            count = 0;
            break;
        case GLFW_REPEAT:
            count++;
            dispatcher.Dispatch(KeyPressedEvent(GlfwKeyMap::GetHazelKey(key), count));
        }
    }

    void WindowsWindow::OnChar(int key)
    {
        dispatcher.Dispatch(KeyTypedEvent(static_cast<Key>(key)));
    }

    void WindowsWindow::OnMouseButton(int button, int action)
    {
        switch (action)
        {
        case GLFW_PRESS:
            dispatcher.Dispatch(MouseButtonPressedEvent(button));
            break;
        case GLFW_RELEASE:
            dispatcher.Dispatch(MouseButtonReleasedEvent(button));
        }
    }

    void WindowsWindow::OnMouseScrolled(double x, double y)
    {
        dispatcher.Dispatch(MouseScrolledEvent(x, y));
    }

    void WindowsWindow::OnMouseMoved(double x, double y)
    {
        dispatcher.Dispatch(MouseMovedEvent(x, y));
    }

    void WindowsWindow::Shutdown()
    {
        CoreInfo("Window destruction start {}.", title);
        glfwDestroyWindow(window);
        delete input;
        CoreInfo("Window destruction done {}.", title);
    }
}