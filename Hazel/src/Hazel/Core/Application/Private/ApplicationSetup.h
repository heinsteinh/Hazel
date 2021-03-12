#pragma once

#include "Hazel/Core/Gui/GuiLayer.h"
#include "Hazel/Core/Logging/Log.h"
#include "ApplicationPrivate.h"
#include "ApplicationInfo.h"
#include "ApplicationEvents.h"
#include "ApplicationGraphicsApi.h"

namespace Hazel
{
	class ApplicationSetup
	{
	public:
		static void SetupApplicationContext(ApplicationPrivate &application, const ApplicationInfo &info)
		{
			Log::Debug("Application setup.");
			InitGraphicsApi(application, info);
			CreateApplicationWindow(application, info);
			CreateGraphicsContext(application, info);
			InitSettings(application, info);
			SetEventCallback(application);
		}

	private:
		static void InitGraphicsApi(ApplicationPrivate &application, const ApplicationInfo &info)
		{
			application.GraphicsApi = ApplicationGraphicsApi::Create(info.GraphicsApi);
		}

		static void CreateApplicationWindow(ApplicationPrivate &application, const ApplicationInfo &info)
		{
			application.Window = application.GraphicsApi->CreateNewWindow(info);
		}

		static void CreateGraphicsContext(ApplicationPrivate &application, const ApplicationInfo &info)
		{
			application.GraphicsContext = application.GraphicsApi->CreateGraphicsContext(*application.Window);
			application.GraphicsContext->SetVerticalSynchronization(info.VerticalSynchronization);
			application.GraphicsContext->SetClearColor(info.ClearColor);
		}

		static void InitSettings(ApplicationPrivate &application, const ApplicationInfo &info)
		{
			application.GuiEnabled = info.GuiEnabled;
			application.Settings.GuiRenderingEnabled = info.GuiRenderingEnabled;
			application.Chrono.Reset();
		}

		static void SetEventCallback(ApplicationPrivate &application)
		{
			application.Window->SetEventCallback([&](Event &e)
			{
				ApplicationEvents::ProcessEvent(application, e);
			});
		}
	};
}