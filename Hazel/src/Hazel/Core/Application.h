#pragma once

#include "Core.h"
#include "Window.h"
#include "Hazel/Layers/Layer.h"

namespace Hazel
{
    class ApplicationImplementation;

    class HAZEL_API Application
    {
    private:
        ApplicationImplementation *implementation;

    public:
        Application();
        virtual ~Application();

        const Window &GetWindow();

        void Run();
        void Quit();
        void PushLayer(Layer *layer);
        void PushOverlay(Layer *overlay);
    };

    Application *CreateApplication();
}