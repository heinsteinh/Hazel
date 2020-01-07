#include "Application.h"

#include "Platform.h"
#include "Hazel/Rendering/RenderCommand.h"
#include "Hazel/ImGui/ImGuiLayer.h"
#include "Hazel/Utils/Reversed.h"

namespace Hazel
{
    Application::Application()
        : window(Platform::Get().CreateNewWindow()),
        imguiLayer(new ImGuiLayer(*window.get()))
    {
        Init();
    }

    Window &Application::GetWindow()
    {
        return *window.get();
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
        imguiLayer->Show(show);
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
        CheckMinimized(e);
        ResetViewport(e);
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
        if (!minimized)
        {
            UpdateLayers(deltaTime);
        }
        RenderImGui();
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

    void Application::CheckMinimized(WindowResizedEvent &e)
    {
        minimized = e.GetWidth() == 0 || e.GetHeight() == 0;
    }

    void Application::ResetViewport(WindowResizedEvent &e)
    {
        RenderCommand(window->GetContext().GetDrawer())
            .SetViewport(Viewport::FromDimensions(
            (float)e.GetWidth(), (float)e.GetHeight()));
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