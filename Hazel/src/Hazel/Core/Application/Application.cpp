#include "Application.h"

#include "Hazel/Core/Logging/Log.h"
#include "Private/ApplicationMainLoop.h"

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
		ApplicationMainLoop::Run(GetInfo(), GetContext());
		Log::Info("Application stopped.");
	}

	void Application::Close()
	{
		Log::Info("Exiting application");
		GetContext().Settings.Running = false;
	}
}