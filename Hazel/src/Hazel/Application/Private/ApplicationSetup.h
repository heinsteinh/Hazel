#pragma once

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
			if (context.GetSettings().GuiEnabled)
			{
				context.GetLayers().PushGuiLayer();
			}
			context.AttachLayers();
			context.SetEventCallback([&](Event &e)
			{
				ApplicationEvents::ProcessEvent(context, e);
			});
		}
	};
}