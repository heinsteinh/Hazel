#include "Application.h"

#include <memory>

#include "Hazel/Events/Events.h"
#include "Hazel/Layers/LayerStack.h"
#include "Hazel/Utils/Reversed.h"

namespace Hazel
{
    class ApplicationImplementation
        : public GenericEventListener,
        public WindowClosedListener
    {
    private:
        std::unique_ptr<Window> window;
        bool running = false;
        LayerStack layers;

    public:
        ApplicationImplementation()
            : window(Window::Create())
        {
            Init();
        }

        inline const Window &GetWindow()
        {
            return *window.get();
        }

        inline void Run()
        {
            CoreInfo("Application started.");
            running = true;
            while (running)
            {
                for (Layer *layer : Reversed(layers))
                {
                    layer->OnUpdate();
                }
                window->OnUpdate();
            }
            CoreInfo("Application stopped.");
        }

        inline void Quit()
        {
            running = false;
        }

        inline void PushLayer(Layer *layer)
        {
            layers.PushLayer(layer);
        }

        inline void PushOverlay(Layer *overlay)
        {
            layers.PushOverlay(overlay);
        }

        virtual void OnEvent(Event &e) override
        {
            CoreTrace("{}", e);
            for (Layer *layer : layers)
            {
                if (e.IsHandled())
                {
                    break;
                }
                EventDispatcher(*layer).Dispatch(e);
            }
        }

        virtual void OnWindowClosed(WindowClosedEvent &e) override
        {
            Quit();
        }

    private:
        inline void Init()
        {
            CoreTrace("Application initialization.");
            SetupWindow();
            CoreTrace("Application initialized.");
        }

        inline void SetupWindow()
        {
            CoreTrace("Main window setup started.");
            window->SetEventListener(this);
            CoreTrace("Main window setup stopped.");
        }
    };

    Application::Application()
        : implementation(new ApplicationImplementation())
    {
    }

    Application::~Application()
    {
    }

    const Window &Application::GetWindow()
    {
        return implementation->GetWindow();
    }

    void Application::Run()
    {
        implementation->Run();
    }

    void Application::Quit()
    {
        implementation->Quit();
    }

    void Application::PushLayer(Layer *layer)
    {
        implementation->PushLayer(layer);
    }

    void Application::PushOverlay(Layer *overlay)
    {
        implementation->PushOverlay(overlay);
    }
}