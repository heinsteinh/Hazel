#pragma once

#include "ApplicationRenderer.h"

namespace Hazel
{
	class ApplicationUpdate
	{
	public:
		static void MainLoopUpdate(ApplicationContext &context, ApplicationLayers &layers)
		{
			ApplicationRenderer::BeginFrame(context, layers);
			context.Window->PollEvents();
			ApplicationRenderer::RenderFrame(context, layers);
			ApplicationRenderer::RenderGui(context, layers);
			ApplicationRenderer::EndFrame(context);
		}

		static void WindowResizeUpdate(ApplicationContext &context, ApplicationLayers &layers)
		{
			ApplicationRenderer::BeginFrame(context, layers);
			ApplicationRenderer::RenderFrame(context, layers);
			ApplicationRenderer::RenderGui(context, layers);
			ApplicationRenderer::EndFrame(context);
		}
	};
}