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

    void WindowsEventManager::SetEventListener(GenericEventListener *listener)
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
        SendEvent(WindowResizedEvent(width, height));
    }

    void WindowsEventManager::OnClose()
    {
        SendEvent(WindowClosedEvent());
    }

    void WindowsEventManager::OnKey(int key, int action)
    {
        switch (action)
        {
        case GLFW_PRESS:
            SendEvent(KeyPressedEvent(GlfwKeyMap::GetHazelKey(key), 0));
            repeatCount = 0;
            break;
        case GLFW_RELEASE:
            SendEvent(KeyReleasedEvent(GlfwKeyMap::GetHazelKey(key)));
            repeatCount = 0;
            break;
        case GLFW_REPEAT:
            repeatCount++;
            SendEvent(KeyPressedEvent(GlfwKeyMap::GetHazelKey(key), repeatCount));
        }
    }

    void WindowsEventManager::OnChar(int key)
    {
        SendEvent(KeyTypedEvent(key));
    }

    void WindowsEventManager::OnMouseButton(int button, int action)
    {
        switch (action)
        {
        case GLFW_PRESS:
            SendEvent(MouseButtonPressedEvent(static_cast<MouseButton>(button)));
            break;
        case GLFW_RELEASE:
            SendEvent(MouseButtonReleasedEvent(static_cast<MouseButton>(button)));
        }
    }

    void WindowsEventManager::OnMouseScrolled(double x, double y)
    {
        SendEvent(MouseScrolledEvent(x, y));
    }

    void WindowsEventManager::OnMouseMoved(double x, double y)
    {
        SendEvent(MouseMovedEvent(x, y));
    }

    void WindowsEventManager::SendEvent(Event &e)
    {
        if (listener)
        {
            listener->OnEvent(e);
        }
    }
}