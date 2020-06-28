#pragma once

#include "ApplicationInfo.h"
#include "Context.h"
#include "Hazel/Layers/Layer.h"
#include "UniquePtr.h"
#include "SharedPtr.h"

namespace Hazel
{
	class ContextManager;

	class Application
	{
	private:
		UniquePtr<ContextManager> contextManager;
		bool running = false;

	public:
		Application(const ApplicationInfo &info = {});
		virtual ~Application();

		Context &GetContext();
		void Run();
		void Quit();
		void PushLayer(const SharedPtr<Layer> &layer);
		void PushOverlay(const SharedPtr<Layer> &overlay);
		void ShowImGui(bool show);
	};

	UniquePtr<Application> CreateApplication();
}