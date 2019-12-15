#include "Hazel.h"

class Sandbox : public Hazel::Application
{
public:
    Sandbox()
    {
        Hazel::Info("Sandbox creation");
        PushLayer(new Hazel::BackgroundLayer());
    };

    virtual ~Sandbox()
    {
    }
};

Hazel::Application *Hazel::CreateApplication()
{
    return new Sandbox();
}