#include "Hazel.h"

#include "TestLayer.h"

namespace Sandbox
{
    class Application : public Hazel::Application
    {
    public:
        Application()
        {
            Hazel::Info("Sandbox application creation");
            PushLayer(new TestLayer(GetWindow()));
        };

        virtual void OnKeyPressed(Hazel::KeyPressedEvent &e) override
        {
            if (e.GetKey() == Hazel::Key::I)
            {
                ShowImGui(true);
            }
            if (e.GetKey() == Hazel::Key::O)
            {
                ShowImGui(false);
            }
        }
    };
}

Hazel::Application *Hazel::CreateApplication()
{
    return new Sandbox::Application();
}