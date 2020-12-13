#pragma once

#include "ApplicationContext.h"
#include "ApplicationUpdate.h"

namespace Hazel
{
	class ApplicationEvents
	{
	public:
		static void ProcessEvent(ApplicationContext &context, Event &e)
		{
			Log::Debug("{}.", e);
			e.Dispatch([&](WindowCloseEvent &e)
			{
				context.GetSettings().Running = false;
			});
			e.Dispatch([&](WindowResizeEvent &e)
			{
				context.GetGraphicsContext().SetViewport({0.0f, e.GetWidth(), 0.0f, e.GetHeight()});
			});
			context.GetLayers().OnEvent(e);
			e.Dispatch([&](WindowResizeEvent &e)
			{
				ApplicationUpdate::WindowResizeUpdate(context);
			});
		}
	};
}