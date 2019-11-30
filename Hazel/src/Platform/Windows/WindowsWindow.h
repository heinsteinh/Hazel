#pragma once

#include "Hazel/Core/Application.h"
#include "Hazel/Core/Window.h"
#include "WindowsInput.h"
#include "GLFW/glfw3.h"
#include "glad/glad.h"

namespace Hazel
{
    class WindowsWindow : public Window
    {
    private:
        static bool glfwInitialized;

        GLFWwindow *window = nullptr;
        WindowsInput *input = nullptr;
        std::string title = "Hazel Engine";
        int width = 1280;
        int height = 720;
        bool vsync = true;
        EventListener *listener = nullptr;
        int count = 0;

    public:
        WindowsWindow();
        virtual ~WindowsWindow();

        virtual const std::string &GetTitle() const override;
        virtual int GetWidth() const override;
        virtual int GetHeight() const override;
        virtual bool IsVSync() const override;
        virtual Input &GetInput() override;

        virtual void SetTitle(const std::string &title) override;
        virtual void Resize(int width, int height) override;
        virtual void SetVSync(bool enabled) override;
        virtual void SetEventListener(EventListener *listener) override;

        virtual void OnUpdate() override;

    private:
        static WindowsWindow &GetWindow(GLFWwindow *window);
        static void OnError(int error, const char *description);

        void Init();
        void InitGlfwIfNotDone();
        void CreateGlfwWindow();
        void InitGladIfNotDone();
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
        void OnEvent(Event &e);
        void Shutdown();
    };
}