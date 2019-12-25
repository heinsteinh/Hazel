#pragma once

#include <string>

#include "Hazel/Events/Events.h"
#include "Hazel/Core/Input.h"
#include "Hazel/Utils/Runnable.h"

namespace Hazel
{
    class HAZEL_API Window : public Runnable
    {
    public:
        static Window *Create();

        virtual ~Window() = default;

        virtual const std::string &GetTitle() const = 0;
        virtual int GetWidth() const = 0;
        virtual int GetHeight() const = 0;
        virtual bool IsVSync() const = 0;

        virtual void SetTitle(const std::string &title) = 0;
        virtual void Resize(int width, int height) = 0;
        virtual void SetVSync(bool enable) = 0;
        virtual void SetEventListener(GenericEventListener *listener) = 0;

        virtual Input &GetInput() const = 0;
        virtual void *GetNativeWindow() const = 0;
    };
}