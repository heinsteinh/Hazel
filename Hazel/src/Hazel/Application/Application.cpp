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
	}

	void Application::Run()
	{
		Log::Info("Application started.");
		ApplicationMainLoop::Run(GetContext());
		Log::Info("Application stopped.");
	}

	void Application::Quit()
	{
		Log::Info("Exiting application");
		GetContext().GetSettings().Running = false;
	}
}