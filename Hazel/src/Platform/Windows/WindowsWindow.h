#pragma once

#include <memory>

#include "Hazel/Core/Window.h"
#include "Hazel/Rendering/Drawing/RenderApi.h"
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
        bool verticalSynchronization = true;

    public:
        WindowsWindow(RenderApi &api);
        virtual ~WindowsWindow();

        Context &GetContext() const override;
        virtual const std::string &GetTitle() const override;
        virtual float GetWidth() const override;
        virtual float GetHeight() const override;
        virtual bool HasVerticalSynchronization() const override;

        virtual void SetTitle(const std::string &title) override;
        virtual void Resize(float width, float height) override;
        virtual void SetVerticalSynchronization(bool enabled) override;
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