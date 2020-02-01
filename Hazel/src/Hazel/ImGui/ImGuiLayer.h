#pragma once

#include "Hazel/Core/Window.h"
#include "Hazel/Core/Layer.h"

namespace Hazel
{
    class ImGuiLayer : public Layer
    {
    private:
        const Window &parent;

    public:
        ImGuiLayer(const Window &parent);
        virtual ~ImGuiLayer() = default;

        void Begin();
        void End();

        virtual void OnAttach() override;
        virtual void OnDetach() override;
        virtual void OnUpdate(Timestep deltaTime) override;
        virtual void OnImGuiRender() override;
        virtual void OnKeyEvent(KeyEvent &e) override;
        virtual void OnMouseEvent(MouseEvent &e) override;

    private:
        void Init();
        void SetupConfigFlags();
        void UpdatePlatforms();
        void Shutdown();
    };
}