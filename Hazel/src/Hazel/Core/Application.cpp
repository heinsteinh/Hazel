#include "Application.h"

#include "ApplicationImplementation.h"

namespace Hazel
{
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