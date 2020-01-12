#pragma once

#include "Window.h"
#include "LayerStack.h"

namespace Hazel
{
    class ImGuiLayer;

    class HAZEL_API Application : public EventListener
    {
    private:
        UniquePtr<Window> window;
        ImGuiLayer *imguiLayer;
        LayerStack layers;
        bool running = false;
        bool showImGui = true;
        double lastTime = 0.0;

    public:
        Application();
        virtual ~Application() = default;

        Window &GetWindow();
        void Run();
        void Quit();
        void PushLayer(Layer *layer);
        void PushOverlay(Layer *overlay);
        void ShowImGui(bool show);

        virtual void OnEvent(Event &e) override;
        virtual void OnWindowClosed(WindowClosedEvent &e) override;
        virtual void OnWindowResized(WindowResizedEvent &e) override;

    private:
        void Init();
        void Update();
        Timestep ComputeDeltaTime();
        void UpdateLayers(Timestep deltaTime);
        void RenderImGui();
    };

    Application *CreateApplication();
}