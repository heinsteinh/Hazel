#include "ApplicationUpdate.h"

#include "ApplicationRenderer.h"
#include "ApplicationEvents.h"

namespace Hazel
{
	void ApplicationUpdate::MainLoopUpdate(ApplicationContext &context)
	{
		ApplicationRenderer::BeginFrame(context);
		ApplicationEvents::PollEvents(context);
		ApplicationRenderer::RenderFrame(context);
		ApplicationRenderer::RenderImGui(context);
		ApplicationRenderer::EndFrame(context);
	}

	void ApplicationUpdate::WindowResizeUpdate(ApplicationContext &context)
	{
		ApplicationRenderer::BeginFrame(context);
		ApplicationRenderer::RenderFrame(context);
		ApplicationRenderer::RenderImGui(context);
		ApplicationRenderer::EndFrame(context);
	}
}