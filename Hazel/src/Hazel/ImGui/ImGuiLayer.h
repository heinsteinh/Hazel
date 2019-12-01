#pragma once

#include "Hazel/Core/Window.h"
#include "Hazel/Core/Layer.h"

namespace Hazel
{
    class HAZEL_API ImGuiLayer : public Layer
    {
    private:
        const Window &parent;
        double time = 0;

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
        void Shutdown();
    };
}