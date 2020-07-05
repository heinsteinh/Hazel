#pragma once

#include "ApplicationInfo.h"
#include "Context.h"
#include "Hazel/Layers/Layer.h"

namespace Hazel
{
	class ContextManager;

	class Application
	{
	private:
		std::unique_ptr<ContextManager> contextManager;
		bool running = false;

	public:
		Application(const ApplicationInfo &info = {});
		virtual ~Application();

		Context &GetContext();
		void Run();
		void Quit();
		void PushLayer(const std::shared_ptr<Layer> &layer);
		void PushOverlay(const std::shared_ptr<Layer> &overlay);
	};

	std::unique_ptr<Application> CreateApplication();
}