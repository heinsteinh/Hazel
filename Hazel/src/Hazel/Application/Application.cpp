#include "Application.h"

#include "Helpers/ApplicationEvents.h"
#include "Helpers/ApplicationMainLoop.h"

namespace Hazel
{
	Application::Application(const ApplicationInfo &info)
		: context(info)
	{
		context.SetEventCallback([this](Event &e)
		{
			ApplicationEvents::DispatchEvent(context, e);
		});
		Log::Debug("Application created.");
	}

	Application::~Application()
	{
		context.SetRunning(false);
		Log::Info("Application destroyed.");
	}

	void Application::Run()
	{
		Log::Info("Application started.");
		ApplicationMainLoop::Run(context);
		Log::Info("Application stopped.");
	}

	bool Application::IsRunning() const
	{
		return context.IsRunning();
	}

	void Application::Quit()
	{
		Log::Info("Quit application.");
		context.SetRunning(false);
	}

	void Application::PushLayer(const std::shared_ptr<Layer> &layer)
	{
		Log::Info("Push layer {}.", layer->GetName());
		context.GetLayers().PushLayer(layer);
	}

	void Application::PushOverlay(const std::shared_ptr<Layer> &overlay)
	{
		Log::Info("Push overlay {}.", overlay->GetName());
		context.GetLayers().PushOverlay(overlay);
	}
}