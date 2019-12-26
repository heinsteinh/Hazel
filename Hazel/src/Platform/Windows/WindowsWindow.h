#pragma once

#include <memory>

#include "Hazel/Core/Window.h"
#include "Hazel/Renderer/Context.h"
#include "WindowsInput.h"
#include "WindowsEventManager.h"

struct GLFWwindow;

namespace Hazel
{
    class WindowsWindow : public Window
    {
    private:
        static const int defaultWidth = 1280;
        static const int defaultHeight = 720;

        GLFWwindow *window = nullptr;
        std::unique_ptr<Context> context;
        std::unique_ptr<WindowsInput> input;
        std::unique_ptr<WindowsEventManager> eventManager;
        std::string title = "Hazel Engine";
        bool vsync = true;

    public:
        WindowsWindow();
        virtual ~WindowsWindow();

        virtual const std::string &GetTitle() const override;
        virtual int GetWidth() const override;
        virtual int GetHeight() const override;
        virtual bool IsVSync() const override;

        virtual void SetTitle(const std::string &title) override;
        virtual void Resize(int width, int height) override;
        virtual void SetVSync(bool enabled) override;
        virtual void SetEventListener(EventListener *listener) override;

        virtual Input &GetInput() const override;
        virtual void *GetNativeWindow() const override;

        virtual void OnUpdate() override;

    private:
        void Init();
        void CreateGlfwWindow();
        void CreateContext();
        void Shutdown();
    };
}