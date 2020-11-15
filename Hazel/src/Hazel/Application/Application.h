#pragma once

#include "Helpers/ApplicationContext.h"
#include "Hazel/Time/Chrono.h"

namespace Hazel
{
	class Application
	{
	private:
		ApplicationContext context;

	public:
		Application(const ApplicationInfo &info = {});
		virtual ~Application();

		void Run();
		bool IsRunning() const;
		void Quit();
		void PushLayer(const std::shared_ptr<Layer> &layer);
		void PushOverlay(const std::shared_ptr<Layer> &overlay);
	};

	std::unique_ptr<Application> CreateApplication();
}