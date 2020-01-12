#include "Hazel.h"
#include "Hazel/Core/EntryPoint.h"

#include "TestLayer.h"
#include "Layer2D.h"

namespace Sandbox
{
    class Application : public Hazel::Application
    {
    public:
        Application()
        {
            Hazel::Info("Sandbox application creation");
            //PushLayer(new TestLayer(GetWindow()));
            PushLayer(new Layer2D(GetWindow()));
            static const glm::vec4 clearColor = {0.45f, 0.55f, 0.60f, 1.00f};
            GetWindow().GetContext().GetDrawer().SetClearColor(clearColor);
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