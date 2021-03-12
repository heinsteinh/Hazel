#include "Application.h"

#include "Hazel/Core/Logging/Log.h"
#include "Private/ApplicationSetup.h"
#include "Private/ApplicationMainLoop.h"

namespace Hazel
{
	Application::Application(const ApplicationInfo &info)
		: application(std::make_unique<ApplicationPrivate>())
	{
		ApplicationSetup::SetupApplicationContext(*application, info);
		Log::Debug("Application created.");
	}

	Application::~Application()
	{
		Log::Info("Application destroyed.");
	}

	void Application::Run()
	{
		Log::Info("Application started.");
		ApplicationMainLoop::Run(*application);
		Log::Info("Application stopped.");
	}

	void Application::PushLayer(std::unique_ptr<ApplicationLayer> layer)
	{
		layer->Attach(*application);
		application->Layers.PushLayer(std::move(layer));
	}

	void Application::PushOverlay(std::unique_ptr<ApplicationLayer> overlay)
	{
		overlay->Attach(*application);
		application->Layers.PushOverlay(std::move(overlay));
	}
}