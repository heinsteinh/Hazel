#include "Hazel.h"

class Sandbox : public Hazel::Application
{
public:
    Sandbox()
    {
        PushOverlay(new Hazel::ImGuiLayer());
    };

    virtual ~Sandbox()
    {
    }
};

Hazel::Application *Hazel::CreateApplication()
{
    Hazel::Info("Sandbox application creation.");
    return new Sandbox();
}