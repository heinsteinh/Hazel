#include "Application.h"

#include "Private/ApplicationMainLoop.h"
#include "Private/EntryPoint.h"

namespace Hazel
{
	Application::Application()
	{
		Log::Debug("Application created.");
	}

	Application::~Application()
	{
		Log::Info("Application destroyed.");
		context.GetSettings().Running = false;
	}

	void Application::Run()
	{
		Log::Info("Application started.");
		ApplicationMainLoop::Run(context);
		Log::Info("Application stopped.");
	}
}