#pragma once

#include <memory>

#include "Hazel/Core/Window.h"
#include "Hazel/Rendering/RenderApi.h"
#include "WindowsInput.h"
#include "WindowsEventManager.h"

struct GLFWwindow;

namespace Hazel
{
    class WindowsWindow : public Window
    {
    private:
        GLFWwindow *window = nullptr;
        std::unique_ptr<Context> context;
        std::unique_ptr<WindowsInput> input;
        std::unique_ptr<WindowsEventManager> eventManager;
        std::string title = "Hazel Engine";
        bool vsync = true;

    public:
        WindowsWindow(RenderApi &api);
        virtual ~WindowsWindow();

        Context &GetContext() const override;
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

        virtual void OnUpdate(Timestep deltaTime) override;

    private:
        void Init(RenderApi &api);
        void CreateGlfwWindow(RenderApi &api);
        void Shutdown();
    };
}