#include "Application.h"

#include "Log.h"
#include "Hazel/ImGui/ImGuiLayer.h"
#include "LayerStack.h"
#include "Hazel/Utils/Reversed.h"

namespace Hazel
{
    Application::Application()
        : window(Window::Create(RenderApi::OpenGL)),
        imguiLayer(new ImGuiLayer(*window.get()))
    {
        Init();
    }

    const Window &Application::GetWindow()
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

    void Application::Init()
    {
        CoreDebug("Application initialization.");
        window->SetEventListener(this);
        window->GetContext().SetClearColor({0.45f, 0.55f, 0.60f, 1.00f});
        PushOverlay(imguiLayer);
        CoreDebug("Application initialized.");
    }

    void Application::Update()
    {
        SetupViewport();
        UpdateLayers();
        RenderImGui();
        window->OnUpdate();
    }

    void Application::SetupViewport()
    {
        const Context &context = window->GetContext();
        context.SetViewport(
            window->GetFrameBufferWidth(),
            window->GetFrameBufferHeight());
        context.Clear();
    }

    void Application::UpdateLayers()
    {
        CoreTrace("Update Layers");
        for (Layer *layer : Reversed(layers))
        {
            layer->OnUpdate();
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