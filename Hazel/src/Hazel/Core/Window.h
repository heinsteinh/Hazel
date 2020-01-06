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

        inline float GetAspectRatio() const
        {
            return (float)GetWidth() / (float)GetHeight();
        }

        virtual Context &GetContext() const = 0;
        virtual const Input &GetInput() const = 0;
        virtual void *GetNativeWindow() const = 0;

        virtual const std::string &GetTitle() const = 0;
        virtual int GetWidth() const = 0;
        virtual int GetHeight() const = 0;
        virtual int GetFrameBufferWidth() const = 0;
        virtual int GetFrameBufferHeight() const = 0;
        virtual bool IsVSync() const = 0;

        virtual void SetTitle(const std::string &title) = 0;
        virtual void Resize(int width, int height) = 0;
        virtual void SetVSync(bool enable) = 0;
        virtual void SetEventListener(EventListener *listener) = 0;
    };
}