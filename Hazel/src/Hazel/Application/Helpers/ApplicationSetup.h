#pragma once

#include "ApplicationContext.h"
#include "ApplicationEvents.h"

namespace Hazel
{
	class ApplicationSetup
	{
	public:
		static inline void Setup(ApplicationContext &context)
		{
			Log::Debug("Application setup.");
			if (!context.GetGraphicsApi())
			{
				context.SetGraphicsApi(GraphicsApiFactory::CreateOpenGLInstance());
			}
			context.CreateApplicationWindow();
			if (context.IsImGuiEnabled())
			{
				context.GetLayers().PushImGuiLayer();
			}
			context.AttachLayers();
			context.SetEventCallback([&](Event &e)
			{
				ApplicationEvents::ProcessEvent(context, e);
			});
		}
	};
}