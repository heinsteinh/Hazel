#include "ApplicationEvents.h"

#include "ApplicationUpdate.h"

namespace Hazel
{
	void ApplicationEvents::PollEvents(ApplicationContext &context)
	{
		context.GetLayers().ClearMouseScrollOffset();
		context.PollEvents();
	}

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
		e.Dispatch([&](WindowResizeEvent &e)
		{
			ApplicationUpdate::WindowResizeUpdate(context);
		});
	}
}