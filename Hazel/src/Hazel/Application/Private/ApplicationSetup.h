#pragma once

#include "ApplicationContext.h"
#include "ApplicationEvents.h"

namespace Hazel
{
	class ApplicationSetup
	{
	public:
		static void Setup(ApplicationContext &context)
		{
			Log::Debug("Application setup.");
			context.LoadGraphicsApi();
			context.CreateApplicationWindow();
			if (context.GetSettings().ImGuiEnabled)
			{
				context.GetLayers().PushImGuiLayer();
			}
			context.AttachLayers();
			context.SetEventCallback([&](Event &e)
			{
				ApplicationEvents::ProcessEvent(context, e);
			});
			context.GetGraphicsContext().SetClearColor({0.30f, 0.30f, 0.30f, 1.00f});
		}
	};
}