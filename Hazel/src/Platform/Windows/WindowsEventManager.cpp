#include "WindowsEventManager.h"

#include "GLFW/glfw3.h"

#include "Hazel/Core/Log.h"
#include "Platform/Windows/GlfwKeyMap.h"

namespace Hazel
{
    static inline WindowsEventManager &GetThis(GLFWwindow *window)
    {
        return *static_cast<WindowsEventManager *>(glfwGetWindowUserPointer(window));
    }

    WindowsEventManager::WindowsEventManager(GLFWwindow *window)
        : window(window)
    {
        Init();
    }

    void WindowsEventManager::SetEventListener(EventListener *listener)
    {
        this->listener = listener;
    }

    void WindowsEventManager::OnUpdate()
    {
        glfwPollEvents();
    }

    void WindowsEventManager::Init()
    {
        glfwSetWindowUserPointer(window, this);
        SetupCallbacks();
    }

    void WindowsEventManager::SetupCallbacks()
    {
        CoreDebug("Callback setup.");
        SetupWindowCallbacks();
        SetupKeyCallbacks();
        SetupMouseCallbacks();
        CoreDebug("Callback setup OK.");
    }

    void WindowsEventManager::SetupWindowCallbacks()
    {
        glfwSetWindowSizeCallback(window, [](GLFWwindow *window, int width, int height)
        {
            GetThis(window).OnResize(width, height);
        });
        glfwSetWindowCloseCallback(window, [](GLFWwindow *window)
        {
            GetThis(window).OnClose();
        });
    }

    void WindowsEventManager::SetupKeyCallbacks()
    {
        glfwSetKeyCallback(window, [](GLFWwindow *window, int key, int scancode, int action, int mods)
        {
            GetThis(window).OnKey(key, action);
        });
        glfwSetCharCallback(window, [](GLFWwindow *window, unsigned int key)
        {
            GetThis(window).OnChar(key);
        });
    }

    void WindowsEventManager::SetupMouseCallbacks()
    {
        glfwSetMouseButtonCallback(window, [](GLFWwindow *window, int button, int action, int mods)
        {
            GetThis(window).OnMouseButton(button, action);
        });
        glfwSetScrollCallback(window, [](GLFWwindow *window, double x, double y)
        {
            GetThis(window).OnMouseScrolled(x, y);
        });
        glfwSetCursorPosCallback(window, [](GLFWwindow *window, double x, double y)
        {
            GetThis(window).OnMouseMoved(x, y);
        });
    }

    void WindowsEventManager::OnResize(int width, int height)
    {
        WindowResizedEvent(width, height).Dispatch(listener);
    }

    void WindowsEventManager::OnClose()
    {
        WindowClosedEvent().Dispatch(listener);
    }

    void WindowsEventManager::OnKey(int key, int action)
    {
        switch (action)
        {
        case GLFW_PRESS:
            KeyPressedEvent(GlfwKeyMap::GetHazelKey(key), 0).Dispatch(listener);
            repeatCount = 0;
            break;
        case GLFW_RELEASE:
            KeyReleasedEvent(GlfwKeyMap::GetHazelKey(key)).Dispatch(listener);
            repeatCount = 0;
            break;
        case GLFW_REPEAT:
            repeatCount++;
            KeyPressedEvent(GlfwKeyMap::GetHazelKey(key), repeatCount).Dispatch(listener);
        }
    }

    void WindowsEventManager::OnChar(int key)
    {
        KeyTypedEvent(key).Dispatch(listener);
    }

    void WindowsEventManager::OnMouseButton(int button, int action)
    {
        switch (action)
        {
        case GLFW_PRESS:
            MouseButtonPressedEvent(static_cast<MouseButton>(button)).Dispatch(listener);
            break;
        case GLFW_RELEASE:
            MouseButtonReleasedEvent(static_cast<MouseButton>(button)).Dispatch(listener);
        }
    }

    void WindowsEventManager::OnMouseScrolled(double x, double y)
    {
        MouseScrolledEvent(x, y).Dispatch(listener);
    }

    void WindowsEventManager::OnMouseMoved(double x, double y)
    {
        MouseMovedEvent(x, y).Dispatch(listener);
    }
}