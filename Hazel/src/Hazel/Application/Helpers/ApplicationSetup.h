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
			if (!context.GetGraphicsApi())
			{
				context.SetGraphicsApi(GraphicsApiFactory::CreateOpenGLInstance());
			}
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
			context.GetGraphicsContext().SetClearColor({0.45f, 0.55f, 0.60f, 1.00f});
		}
	};
}