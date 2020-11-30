#pragma once

#include "ApplicationRenderer.h"

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
			context.GetLayers().DispatchEvent(e);
		}
	};
}