#include "Application.h"

#include "ContextManager.h"

namespace Hazel
{
	Application::Application(const ApplicationInfo &info)
		: contextManager(MakeUnique<ContextManager>(info))
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
			Log::Trace("Updating application.");
			contextManager->OnUpdate();
		}
		Log::Info("Application stopped.");
	}

	void Application::Quit()
	{
		Log::Info("Quit application.");
		running = false;
	}

	void Application::PushLayer(const SharedPtr<Layer> &layer)
	{
		Log::Info("Push layer {}.", layer->GetName());
		contextManager->GetLayerManager().PushLayer(layer);
	}

	void Application::PushOverlay(const SharedPtr<Layer> &overlay)
	{
		Log::Info("Push overlay {}.", overlay->GetName());
		contextManager->GetLayerManager().PushOverlay(overlay);
	}

	void Application::ShowImGui(bool show)
	{
		Log::Info("Show ImGui {}.", show);
		contextManager->GetLayerManager().ShowImGui(show);
	}
}