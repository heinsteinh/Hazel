#pragma once

#include <string>

#include "Hazel/Events/Events.h"
#include "Hazel/Core/Input.h"

namespace Hazel
{
    class HAZEL_API Window
    {
    public:
        static Window *Create();

        virtual ~Window() = default;

        virtual const std::string &GetTitle() const = 0;
        virtual int GetWidth() const = 0;
        virtual int GetHeight() const = 0;
        virtual bool IsVSync() const = 0;
        virtual Input &GetInput() = 0;

        virtual void SetTitle(const std::string &title) = 0;
        virtual void Resize(int width, int height) = 0;
        virtual void SetVSync(bool enable) = 0;
        virtual void SetEventListener(EventListener *listener) = 0;

        virtual void OnUpdate() = 0;
    };
}