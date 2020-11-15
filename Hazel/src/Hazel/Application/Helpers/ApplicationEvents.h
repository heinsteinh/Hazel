#pragma once

#include "ApplicationContext.h"
#include "ApplicationLayers.h"
#include "Hazel/Logging/Log.h"

namespace Hazel
{
	class ApplicationEvents
	{
	public:
		static inline void DispatchEvent(ApplicationContext &context, Event &e)
		{
			Log::Debug("{}.", e);
			e.Dispatch([&](WindowCloseEvent &e)
			{
				context.SetRunning(false);
			});
			e.Dispatch([&](WindowResizeEvent &e)
			{
				auto size = e.GetSize();
				context.GetGraphicsContext().SetViewport({0.0f, size.Width, 0.0f, size.Height});
			});
			context.GetLayers().DispatchEvent(e);
		}
	};
}