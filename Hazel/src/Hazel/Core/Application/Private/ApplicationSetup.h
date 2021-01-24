#pragma once

#include "ApplicationInfo.h"
#include "ApplicationContext.h"
#include "ApplicationLayers.h"
#include "ApplicationEvents.h"
#include "Hazel/Core/Gui/GuiLayer.h"
#include "Hazel/Core/Logging/Log.h"
#include "Hazel/Rendering/GraphicsApi/GraphicsApiFactory.h"

namespace Hazel
{
	class ApplicationSetup
	{
	public:
		static void Setup(ApplicationInfo &info, ApplicationContext &context, ApplicationLayers &layers)
		{
			Log::Debug("Application setup.");
			SetupWindow(info, context);
			SetupEventSystem(context, layers);
			SetupLayers(context, layers);
			context.Chrono.Reset();
		}

	private:
		static void SetupWindow(ApplicationInfo &info, ApplicationContext &context)
		{
			context.GraphicsApi = GraphicsApiFactory::CreateApi(info.GraphicsApi);
			info.WindowInfo.GraphicsApi = context.GraphicsApi.get();
			context.Window = std::make_unique<Window>(info.WindowInfo);
			context.Window->GetGraphicsContext().SetClearColor(info.ClearColor);
		}

		static void SetupEventSystem(ApplicationContext &context, ApplicationLayers &layers)
		{
			context.Window->SetEventCallback([&](Event &e)
			{
				ApplicationEvents::ProcessEvent(context, layers, e);
			});
		}

		static void SetupLayers(ApplicationContext &context, ApplicationLayers &layers)
		{
			if (context.Settings.GuiEnabled)
			{
				layers.GuiLayer = std::make_shared<GuiLayer>();
				layers.Stack.PushOverlay(layers.GuiLayer);
			}
			for (const auto &layer : layers.Stack)
			{
				layer->Attach(context);
				layer->OnAttach();
			}
		}
	};
}