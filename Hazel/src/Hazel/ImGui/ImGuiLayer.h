#pragma once

#include "Hazel/Core/Window.h"
#include "Hazel/Core/Layer.h"

namespace Hazel
{
    class ImGuiLayer : public Layer
    {
    private:
        bool show = false;
        const Window &parent;

    public:
        ImGuiLayer(const Window &parent);
        virtual ~ImGuiLayer();

        void Begin();
        void End();
        void Show(bool open);
        bool IsShown() const;

        virtual void OnAttach() override;
        virtual void OnDetach() override;
        virtual void OnUpdate(Timestep deltaTime) override;
        virtual void OnImGuiRender() override;

    private:
        void Init();
        void SetupConfigFlags();
        void UpdatePlatforms();
        void Shutdown();
    };
}