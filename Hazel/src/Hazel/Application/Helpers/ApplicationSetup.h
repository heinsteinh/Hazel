#pragma once

#include "ApplicationContext.h"
#include "Hazel/Logging/Log.h"

namespace Hazel
{
	class ApplicationSetup
	{
	public:
		static inline void Setup(ApplicationContext &context)
		{
			Log::Info("Application setup.");
			context.CreateApplicationWindow();
			context.SetupImGui();
			context.AttachLayers();
			context.SetEventCallback([&](Event &e)
			{
				Log::Debug("{}.", e);
				ApplicationEvents::ProcessEvent(context, e);
			});
		}
	};
}