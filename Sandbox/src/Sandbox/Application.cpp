#include "Hazel.h"
#include "Hazel/Core/EntryPoint.h"

#include "Layer2D.h"

namespace Sandbox
{
    class Application : public Hazel::Application
    {
    public:
        Application()
        {
            Hazel::Info("Sandbox application creation");
            PushLayer(new Layer2D(GetWindow()));
            GetWindow().GetContext().GetDrawer().SetClearColor({0.45f, 0.55f, 0.60f, 1.00f});
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