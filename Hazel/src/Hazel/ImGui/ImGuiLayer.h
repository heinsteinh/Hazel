#pragma once

#include "Hazel/Core/Window.h"
#include "Hazel/Core/Layer.h"

namespace Hazel
{
    class ImGuiLayer : public Layer
    {
    private:
        const std::string name = "ImGui";
        bool open = true;
        const Window &parent;

    public:
        ImGuiLayer(const Window &parent);
        virtual ~ImGuiLayer();

        virtual const std::string &GetName() const override;
        virtual void OnAttach() override;
        virtual void OnDetach() override;
        virtual void OnUpdate() override;
        virtual void OnImGuiRender() override;

        void Begin();
        void End();

    private:
        void Init();
        void SetupConfigFlags();
        void UpdatePlatforms();
        void Shutdown();
    };
}