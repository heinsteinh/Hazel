#pragma once

#include "Hazel/Core/Window.h"
#include "Hazel/Core/Layer.h"

namespace Hazel
{
    class ImGuiLayer : public Layer
    {
    private:
        const std::string name = "ImGui";
        bool show = false;
        const Window &parent;

    public:
        ImGuiLayer(const Window &parent);
        virtual ~ImGuiLayer();

        void Begin();
        void End();
        void Show(bool open);
        bool IsShown() const;

        virtual const std::string &GetName() const override;
        virtual void OnAttach() override;
        virtual void OnDetach() override;
        virtual void OnUpdate() override;
        virtual void OnImGuiRender() override;

    private:
        void Init();
        void SetupConfigFlags();
        void UpdatePlatforms();
        void Shutdown();
    };
}