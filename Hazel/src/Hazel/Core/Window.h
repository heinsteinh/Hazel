#pragma once

#include "Hazel/Core/Input.h"
#include "Hazel/Events/Events.h"
#include "Hazel/Rendering/Context.h"
#include "Hazel/Utils/Runnable.h"

namespace Hazel
{
    class HAZEL_API Window : public Runnable
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

        inline Viewport GetViewport() const
        {
            return Viewport::FromDimensions(GetWidth(), GetHeight());
        }

        virtual Context &GetContext() const = 0;
        virtual const Input &GetInput() const = 0;
        virtual void *GetNativeWindow() const = 0;

        virtual const std::string &GetTitle() const = 0;
        virtual float GetWidth() const = 0;
        virtual float GetHeight() const = 0;
        virtual bool IsVSync() const = 0;

        virtual void SetTitle(const std::string &title) = 0;
        virtual void Resize(float width, float height) = 0;
        virtual void SetVSync(bool enable) = 0;
        virtual void SetEventListener(EventListener *listener) = 0;
    };
}