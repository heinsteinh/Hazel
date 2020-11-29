#pragma once

#include "ApplicationContext.h"
#include "Hazel/Geometry/Viewport.h"

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
				auto &windowSize = e.GetWindowSize();
				context.GetGraphicsContext().SetViewport({0.0f, windowSize.x, 0.0f, windowSize.y});
			});
			context.GetLayers().DispatchEvent(e);
		}
	};
}