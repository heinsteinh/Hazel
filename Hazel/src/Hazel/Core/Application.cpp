#include "Application.h"

#include <memory>

#include "Logger.h"
#include "Hazel/ImGui/ImGuiLayer.h"
#include "LayerStack.h"
#include "Hazel/Events/Events.h"
#include "Hazel/Utils/Reversed.h"

namespace Hazel
{
    class ApplicationImplementation : public EventListener
    {
    private:
        std::unique_ptr<Window> window;
        ImGuiLayer *imgui;
        bool running = false;
        LayerStack layers;

    public:
        ApplicationImplementation()
            : window(Window::Create()),
            imgui(new Hazel::ImGuiLayer(*window.get()))
        {
            Init();
        }

        inline const Window &GetWindow()
        {
            return *window.get();
        }

        inline void Run()
        {
            CoreInfo("Application started.");
            running = true;
            while (running)
            {
                UpdateLayers();
                RenderImGui();
                window->OnUpdate();
            }
            CoreInfo("Application stopped.");
        }

        inline void Quit()
        {
            running = false;
        }

        inline void PushLayer(Layer *layer)
        {
            layers.PushLayer(layer);
        }

        inline void PushOverlay(Layer *overlay)
        {
            layers.PushOverlay(overlay);
        }

        virtual void OnEvent(Event &e) override
        {
            CoreDebug("{}", e);
            for (Layer *layer : layers)
            {
                EventDispatcher(layer).Dispatch(e);
            }
        }

        virtual void OnWindowClosed(WindowClosedEvent &e) override
        {
            Quit();
        }

    private:
        inline void Init()
        {
            CoreDebug("Application initialization.");
            SetupWindow();
            PushOverlay(imgui);
            CoreDebug("Application initialized.");
        }

        inline void SetupWindow()
        {
            CoreDebug("Main window setup started.");
            window->SetEventListener(this);
            CoreDebug("Main window setup stopped.");
        }

        inline void UpdateLayers()
        {
            CoreTrace("Update Layers");
            for (Layer *layer : Reversed(layers))
            {
                layer->OnUpdate();
            }
        }

        inline void RenderImGui()
        {
            CoreTrace("Render ImGui");
            imgui->Begin();
            for (Layer *layer : Reversed(layers))
            {
                layer->OnImGuiRender();
            }
            imgui->End();
        }
    };

    Application::Application()
        : implementation(new ApplicationImplementation())
    {
    }

    Application::~Application()
    {
        delete implementation;
    }

    const Window &Application::GetWindow()
    {
        return implementation->GetWindow();
    }

    void Application::Run()
    {
        implementation->Run();
    }

    void Application::Quit()
    {
        implementation->Quit();
    }

    void Application::PushLayer(Layer *layer)
    {
        implementation->PushLayer(layer);
    }

    void Application::PushOverlay(Layer *overlay)
    {
        implementation->PushOverlay(overlay);
    }
}