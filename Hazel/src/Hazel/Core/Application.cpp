#include "Application.h"

#include "ContextManager.h"

namespace Hazel
{
	Application::Application(const ContextInfo &info)
		: contextManager(std::make_unique<ContextManager>(info))
	{
		Log::Debug("Application created.");
	}

	Application::~Application()
	{
		running = false;
		Log::Info("Application destroyed.");
	}

	Context &Application::GetContext()
	{
		return contextManager->GetContext();
	}

	void Application::Run()
	{
		Log::Info("Application started.");
		running = true;
		while (running && !contextManager->HasWindowClosed())
		{
			Log::Trace("Update.");
			contextManager->OnUpdate();
		}
		Log::Info("Application stopped.");
	}

	void Application::Quit()
	{
		Log::Info("Quit application.");
		running = false;
	}

	void Application::PushLayer(const std::shared_ptr<Layer> &layer)
	{
		Log::Info("Push layer {}.", layer->GetName());
		contextManager->GetLayerManager().PushLayer(layer);
	}

	void Application::PushOverlay(const std::shared_ptr<Layer> &overlay)
	{
		Log::Info("Push overlay {}.", overlay->GetName());
		contextManager->GetLayerManager().PushOverlay(overlay);
	}
}