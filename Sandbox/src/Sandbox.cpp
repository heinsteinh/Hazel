#include "Hazel.h"

class Sandbox : public Hazel::Application
{
public:
    Sandbox()
    {
        Hazel::Info("Sandox creation");
    };

    virtual ~Sandbox()
    {
    }
};

Hazel::Application *Hazel::CreateApplication()
{
    return new Sandbox();
}