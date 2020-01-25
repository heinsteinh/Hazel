#include "Layer2D.h"

namespace Sandbox
{
    Layer2D::Layer2D(Hazel::Window &parent)
        : parent(parent),
        renderer(parent),
        cameraController(parent)
    {
    }

    void Layer2D::OnAttach()
    {
        texture = parent.GetContext().GetFactory().CreateTexture2D("assets\\textures\\Test.jpg");
    }

    void Layer2D::OnDetach()
    {
    }

    void Layer2D::OnUpdate(Hazel::Timestep deltaTime)
    {
        static const std::string section = __FUNCTION__;
        Hazel::Timer timer(section, this);

        framerate = 1.0f / deltaTime.ToSeconds();

        parent.GetContext().GetDrawer().Clear();

        cameraController.OnUpdate(deltaTime);

        renderer.BeginScene(cameraController.GetCamera());
        renderer.DrawQuad({-0.5f, 0.5f, -0.5f, 0.5f}, color);
        renderer.DrawQuad({-2.6f, -1.0f, 0.0f, 0.9f}, texture);
        renderer.EndScene();
    }

    void Layer2D::OnImGuiRender()
    {
        if (showFps)
        {
            ImGui::Begin("Framerate", &showFps);
            ImGui::Text("%.2f FPS", framerate);
            ImGui::End();
        }
        if (showColorPicker)
        {
            ImGui::Begin("Settings", &showColorPicker);
            ImGui::ColorPicker4("Color", glm::value_ptr(color));
            ImGui::End();
        }
    }

    void Layer2D::OnEvent(Hazel::Event &e)
    {
        e.Dispatch(&cameraController);
    }

    void Layer2D::OnKeyPressed(Hazel::KeyPressedEvent &e)
    {
        if (e.GetKey() == Hazel::Key::R)
        {
            cameraController.SetRotationEnabled(!cameraController.HasRotationEnabled());
        }
        if (e.GetKey() == Hazel::Key::I)
        {
            showFps = showColorPicker = true;
        }
    }

    void Layer2D::OnMeasurement(const std::string &name, Hazel::Timestep duration)
    {
        Hazel::Debug("{} duration: {}ms", name, duration.ToMilliseconds());
    }
}