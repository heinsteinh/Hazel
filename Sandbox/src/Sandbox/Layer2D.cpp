#include "Layer2D.h"

namespace Sandbox
{
    Layer2D::Layer2D(Hazel::Window &parent)
        : parent(parent),
        renderer(parent.GetContext()),
        cameraController(parent)
    {
    }

    void Layer2D::OnAttach()
    {
        texture = Hazel::TextureFactory(parent.GetContext()).Create("assets\\textures\\Test.jpg");
    }

    void Layer2D::OnDetach()
    {
    }

    void Layer2D::OnUpdate(Hazel::Timestep deltaTime)
    {
        framerate = 1.0f / deltaTime.ToSeconds();

        parent.GetContext().GetDrawer().Clear();

        cameraController.OnUpdate(deltaTime);

        float speed = 0.1f;

        auto &input = parent.GetInput();
        if (input.IsKeyPressed(Hazel::Key::Up))
        {
            transform.TranslateY(speed);
        }
        if (input.IsKeyPressed(Hazel::Key::Down))
        {
            transform.TranslateY(-speed);
        }
        if (input.IsKeyPressed(Hazel::Key::Right))
        {
            transform.TranslateX(speed);
        }
        if (input.IsKeyPressed(Hazel::Key::Left))
        {
            transform.TranslateX(-speed);
        }

        renderer.BeginScene(cameraController.GetCamera());
        // DRAW
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
        auto key = e.GetKey();
        if (key == Hazel::Key::R)
        {
            cameraController.SetRotationEnabled(!cameraController.HasRotationEnabled());
        }
        if (key == Hazel::Key::I)
        {
            showFps = showColorPicker = true;
        }
        if (key == Hazel::Key::Backspace)
        {
            color = {1.0f, 0.0f, 0.0f, 1.0f};
        }
    }

    void Layer2D::OnMeasurement(const std::string &name, Hazel::Timestep duration)
    {
        Hazel::Debug("{} duration: {}ms", name, duration.ToMilliseconds());
    }
}