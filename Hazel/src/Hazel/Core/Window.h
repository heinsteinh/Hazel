#pragma once

#include <string>

#include "Hazel/Events/Events.h"
#include "Hazel/Core/Input.h"
#include "Hazel/Utils/Runnable.h"
#include "Hazel/Renderer/RenderApi.h"

namespace Hazel
{
    class HAZEL_API Window : public Runnable
    {
    public:
        static Window *Create(const RenderApi &api);

        virtual ~Window() = default;

        virtual const Context &GetContext() const = 0;
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

        virtual Input &GetInput() const = 0;
        virtual void *GetNativeWindow() const = 0;
    };
}