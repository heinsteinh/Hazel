#pragma once

#include "ApplicationPrivate.h"
#include "ApplicationUpdate.h"

namespace Hazel
{
	class ApplicationMainLoop
	{
	public:
		static void Run(ApplicationPrivate &application)
		{
			Init(application);
			while (IsRunning(application))
			{
				ApplicationUpdate::MainLoopUpdate(application);
			}
		}

	private:
		static void Init(ApplicationPrivate &application)
		{
			PushGuiLayer(application);
			ResetTime(application);
			Start(application);
		}

		static void PushGuiLayer(ApplicationPrivate &application)
		{
			if (application.GuiEnabled)
			{
				auto guiLayer = std::make_unique<GuiLayer>();
				application.GuiLayer = guiLayer.get();
				application.Layers.PushOverlay(std::move(guiLayer));
				application.GuiLayer->Attach(application);
			}
		}

		static void ResetTime(ApplicationPrivate &application)
		{
			application.Chrono.Reset();
		}

		static void Start(ApplicationPrivate &application)
		{
			application.Settings.Running = true;
		}

		static bool IsRunning(ApplicationPrivate &application)
		{
			return application.Settings.Running;
		}
	};
}