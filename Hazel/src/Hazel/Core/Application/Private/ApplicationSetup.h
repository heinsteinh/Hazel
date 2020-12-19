#pragma once

#include "ApplicationInfo.h"
#include "ApplicationEvents.h"
#include "Hazel/Rendering/GraphicsApi/GraphicsApiFactory.h"

namespace Hazel
{
	class ApplicationSetup
	{
	public:
		static void Setup(ApplicationInfo &info, ApplicationContext &context)
		{
			Log::Debug("Application setup.");
			SetupWindow(info, context);
			SetupEventSystem(context);
			SetupLayers(context);
			context.Chrono.Reset();
		}

	private:
		static void SetupWindow(ApplicationInfo &info, ApplicationContext &context)
		{
			context.GraphicsApi = GraphicsApiFactory::Create(info.GraphicsApi);
			info.WindowInfo.GraphicsApi = context.GraphicsApi.get();
			context.Window = std::make_unique<Window>(info.WindowInfo);
			context.Window->GetGraphicsContext().SetClearColor(info.ClearColor);
		}

		static void SetupEventSystem(ApplicationContext &context)
		{
			context.EventSystem.SetWindow(*context.Window);
			context.EventSystem.SetCallback([&](Event &e)
			{
				ApplicationEvents::ProcessEvent(context, e);
			});
		}

		static void SetupLayers(ApplicationContext &context)
		{
			if (context.Settings.GuiEnabled)
			{
				context.Layers.PushGuiLayer();
			}
			context.Layers.OnAttach(context);
		}
	};
}