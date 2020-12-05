#include "ApplicationEvents.h"

namespace Hazel
{
	void ApplicationEvents::ProcessEvent(ApplicationContext &context, Event &e)
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
		context.GetLayers().DispatchEvent(e);
	}
}