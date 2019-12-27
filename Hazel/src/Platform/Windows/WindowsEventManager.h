#pragma once

#include "Hazel/Events/Events.h"

struct GLFWwindow;

namespace Hazel
{
    class WindowsEventManager
    {
    private:
        GLFWwindow *window = nullptr;
        EventListener *listener = nullptr;
        int repeatCount = 0;

    public:
        WindowsEventManager(GLFWwindow *window);

        void SetEventListener(EventListener *listener);
        void PollEvents();

    private:
        void Init();
        void SetupCallbacks();
        void SetupWindowCallbacks();
        void SetupKeyCallbacks();
        void SetupMouseCallbacks();
        void OnResize(int width, int height);
        void OnClose();
        void OnKey(int key, int action);
        void OnChar(int key);
        void OnMouseButton(int button, int action);
        void OnMouseScrolled(double x, double y);
        void OnMouseMoved(double x, double y);
    };
}