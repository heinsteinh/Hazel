#pragma once

#include <memory>

#include "ApplicationInfo.h"

namespace Hazel
{
	struct ApplicationPrivate;
	class ApplicationLayer;

	class Application
	{
	private:
		std::unique_ptr<ApplicationPrivate> application;

	public:
		Application(const ApplicationInfo &info);
		virtual ~Application();

		void Run();
		void PushLayer(std::unique_ptr<ApplicationLayer> layer);
		void PushOverlay(std::unique_ptr<ApplicationLayer> overlay);
	};
}