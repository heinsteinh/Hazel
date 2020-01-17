#include "Application.h"

#include "Platform.h"
#include "Hazel/ImGui/ImGuiLayer.h"
#include "Hazel/Rendering/RenderCommand.h"
#include "Hazel/Utils/Reversed.h"

namespace Hazel
{
    Application::Application()
        : window(Platform::Get().CreateNewWindow()),
        imguiLayer(new ImGuiLayer(*window))
    {
        Init();
    }

    Window &Application::GetWindow()
    {
        return *window;
    }

    void Application::Run()
    {
        CoreInfo("Application started.");
        running = true;
        while (running)
        {
            Update();
        }
        CoreInfo("Application stopped.");
    }

    void Application::Quit()
    {
        running = false;
    }

    void Application::PushLayer(Layer *layer)
    {
        layers.PushLayer(layer);
    }

    void Application::PushOverlay(Layer *overlay)
    {
        layers.PushOverlay(overlay);
    }

    void Application::ShowImGui(bool show)
    {
        showImGui = show;
    }

    void Application::OnEvent(Event &e)
    {
        CoreDebug("{}", e);
        for (Layer *layer : layers)
        {
            e.Dispatch(layer);
        }
    }

    void Application::OnWindowClosed(WindowClosedEvent &e)
    {
        Quit();
    }

    void Application::OnWindowResized(WindowResizedEvent &e)
    {
        RenderCommand(*window).SetViewport({0.0f, e.GetWidth(), 0.0f, e.GetHeight()});
    }

    void Application::Init()
    {
        CoreDebug("Application initialization.");
        window->SetEventListener(this);
        PushOverlay(imguiLayer);
        CoreDebug("Application initialized.");
    }

    void Application::Update()
    {
        Timestep deltaTime = ComputeDeltaTime();
        if (!window->IsMinimized())
        {
            UpdateLayers(deltaTime);
        }
        if (showImGui)
        {
            RenderImGui();
        }
        window->OnUpdate(deltaTime);
    }

    Timestep Application::ComputeDeltaTime()
    {
        double time = Platform::Get().GetTime();
        double deltaTime = time - lastTime;
        lastTime = time;
        CoreTrace("Frame Rate: {}", 1.0 / deltaTime);
        return Timestep::FromSeconds((float)deltaTime);
    }

    void Application::UpdateLayers(Timestep deltaTime)
    {
        CoreTrace("Update Layers");
        for (Layer *layer : Reversed(layers))
        {
            layer->OnUpdate(deltaTime);
        }
    }

    void Application::RenderImGui()
    {
        CoreTrace("Render ImGui");
        imguiLayer->Begin();
        for (Layer *layer : Reversed(layers))
        {
            layer->OnImGuiRender();
        }
        imguiLayer->End();
    }
}