#pragma once

#include "Hazel/Core/Input.h"
#include "Hazel/Events/Events.h"
#include "Hazel/Rendering/Drawing/Context.h"
#include "Hazel/Utils/Updatable.h"

namespace Hazel
{
    class HAZEL_API Window : public Updatable
    {
    public:
        virtual ~Window() = default;

        inline bool IsMinimized() const
        {
            return GetWidth() == 0.0f || GetHeight() == 0.0f;
        }

        inline float GetAspectRatio() const
        {
            auto height = GetHeight();
            return height ? GetWidth() / height : 0.0f;
        }

        inline Rectangle GetViewport() const
        {
            return Rectangle::FromSize(GetWidth(), GetHeight());
        }

        virtual Context &GetContext() const = 0;
        virtual const Input &GetInput() const = 0;
        virtual void *GetNativeWindow() const = 0;

        virtual const std::string &GetTitle() const = 0;
        virtual float GetWidth() const = 0;
        virtual float GetHeight() const = 0;
        virtual bool HasVerticalSynchronization() const = 0;

        virtual void SetTitle(const std::string &title) = 0;
        virtual void Resize(float width, float height) = 0;
        virtual void SetVerticalSynchronization(bool enable) = 0;
        virtual void SetEventListener(EventListener *listener) = 0;
    };
}