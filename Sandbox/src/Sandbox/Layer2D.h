#pragma once

#include "Hazel.h"

namespace Sandbox
{
    class Layer2D : public Hazel::Layer, public Hazel::TimerListener
    {
    private:
        Hazel::Window &parent;
        Hazel::Renderer2D renderer;

        Hazel::OrthographicCameraController cameraController;

        float framerate = 0.0f;

        glm::vec4 red = {1.0f, 0.0f, 0.0f, 1.0f};
        glm::vec4 green = {0.0f, 1.0f, 0.0f, 1.0f};
        glm::vec4 blue = {0.0f, 0.0f, 1.0f, 1.0f};
        glm::vec4 color = red;

        Hazel::SharedPtr<Hazel::Texture> texture;

        bool showFps = true;
        bool showColorPicker = true;

    public:
        Layer2D(Hazel::Window &parent);
        virtual ~Layer2D() = default;

        virtual void OnAttach() override;
        virtual void OnDetach() override;
        virtual void OnUpdate(Hazel::Timestep deltaTime) override;
        virtual void OnImGuiRender() override;
        virtual void OnEvent(Hazel::Event &e) override;
        virtual void OnKeyPressed(Hazel::KeyPressedEvent &e) override;
        virtual void OnMeasurement(const std::string &name, Hazel::Timestep duration) override;
    };
}