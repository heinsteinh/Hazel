#pragma once

#include <memory>

#include "Core.h"
#include "Window.h"
#include "LayerStack.h"

namespace Hazel
{
    class ImGuiLayer;

    class HAZEL_API Application : public EventListener
    {
    private:
        std::unique_ptr<Window> window;
        ImGuiLayer *imguiLayer;
        bool running = false;
        LayerStack layers;

    public:
        Application();

        const Window &GetWindow();
        void Run();
        void Quit();
        void PushLayer(Layer *layer);
        void PushOverlay(Layer *overlay);

        virtual void OnEvent(Event &e) override;
        virtual void OnWindowClosed(WindowClosedEvent &e) override;

    private:
        void Init();
        void Update();
        void UpdateLayers();
        void RenderImGui();
    };

    Application *CreateApplication();
}