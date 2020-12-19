#pragma once

#include "ApplicationContext.h"
#include "ApplicationUpdate.h"
#include "Hazel/Core/Events/WindowCloseEvent.h"
#include "Hazel/Core/Events/WindowResizeEvent.h"

namespace Hazel
{
	class ApplicationEvents
	{
	public:
		static void ProcessEvent(ApplicationContext &context, Event &e)
		{
			//Log::Debug("{}.", e);
			e.Dispatch([&](WindowCloseEvent &e)
			{
				context.Settings.Running = false;
			});
			e.Dispatch([&](WindowResizeEvent &e)
			{
				context.Window->GetGraphicsContext().SetViewport({0.0f, e.GetWidth(), 0.0f, e.GetHeight()});
			});
			context.Layers.OnEvent(e);
			e.Dispatch([&](WindowResizeEvent &e)
			{
				ApplicationUpdate::WindowResizeUpdate(context);
			});
		}
	};
}