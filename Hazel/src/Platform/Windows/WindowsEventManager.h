#pragma once

#include "Hazel/Events/Events.h"
#include "Hazel/Utils/Runnable.h"

struct GLFWwindow;

namespace Hazel
{
    class WindowsEventManager : public Runnable
    {
    private:
        GLFWwindow *window = nullptr;
        EventDispatcher dispatcher;
        int repeatCount = 0;

    public:
        WindowsEventManager(GLFWwindow *window);

        void SetEventListener(EventListener *listener);

        virtual void OnUpdate() override;

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