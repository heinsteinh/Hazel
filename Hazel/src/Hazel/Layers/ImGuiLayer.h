#pragma once

#include "Hazel/Core/Window.h"
#include "Hazel/Layers/Layer.h"

namespace Hazel
{
    class HAZEL_API ImGuiLayer : public Layer
    {
    private:
        double time = 0;

    public:
        ImGuiLayer();
        virtual ~ImGuiLayer();

        virtual const std::string &GetName() const override;

        virtual void OnAttach() override;
        virtual void OnDetach() override;
        virtual void OnUpdate() override;

        virtual void OnMouseButtonPressed(MouseButtonPressedEvent &e) override;
        virtual void OnMouseButtonReleased(MouseButtonReleasedEvent &e) override;
        virtual void OnMouseMoved(MouseMovedEvent &e) override;
        virtual void OnMouseScrolled(MouseScrolledEvent &e) override;
        virtual void OnKeyPressed(KeyPressedEvent &e) override;
        virtual void OnKeyReleased(KeyReleasedEvent &e) override;
        virtual void OnKeyTyped(KeyTypedEvent &e) override;
        virtual void OnWindowResized(WindowResizedEvent &e) override;
    };
}