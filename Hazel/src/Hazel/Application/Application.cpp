#include "Application.h"

#include "Helpers/ApplicationEvents.h"
#include "Helpers/ApplicationMainLoop.h"
#include "Helpers/EntryPoint.h"

namespace Hazel
{
	Application::Application()
	{
		Log::Debug("Application created.");
	}

	Application::~Application()
	{
		Log::Info("Application destroyed.");
		context->SetRunning(false);
	}

	void Application::Run()
	{
		Log::Info("Application started.");
		context = std::make_unique<ApplicationContext>(info);
		ApplicationMainLoop::Run(*context);
		Log::Info("Application stopped.");
	}
}