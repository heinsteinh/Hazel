#pragma once

#include "Hazel/Core/Core.h"
#include "Hazel/Core/Layer.h"

namespace Hazel
{
    class HAZEL_API BackgroundLayer : public Layer
    {
    public:
        virtual const std::string &GetName() const override;
        virtual void OnAttach() override;
        virtual void OnDetach() override;
        virtual void OnUpdate() override;
        virtual void OnImGuiRender() override;
    };
}