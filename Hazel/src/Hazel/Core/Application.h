#pragma once

#include "Window.h"
#include "LayerStack.h"
#include "Timestep.h"

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
        double lastTime = 0.0;

    public:
        Application();

        Window &GetWindow();
        void Run();
        void Quit();
        void PushLayer(Layer *layer);
        void PushOverlay(Layer *overlay);
        void ShowImGui(bool show);

        virtual void OnEvent(Event &e) override;
        virtual void OnWindowClosed(WindowClosedEvent &e) override;

    private:
        void Init();
        void Update();
        Timestep ComputeDeltaTime();
        void SetupViewport();
        void UpdateLayers(Timestep deltaTime);
        void RenderImGui();
    };

    Application *CreateApplication();
}