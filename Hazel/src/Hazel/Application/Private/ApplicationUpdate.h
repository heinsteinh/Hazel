#pragma once

#include "ApplicationRenderer.h"

namespace Hazel
{
	class ApplicationUpdate
	{
	public:
		static void MainLoopUpdate(ApplicationContext &context)
		{
			ApplicationRenderer::BeginFrame(context);
			context.PollEvents();
			ApplicationRenderer::RenderFrame(context);
			ApplicationRenderer::RenderImGui(context);
			ApplicationRenderer::EndFrame(context);
		}

		static void WindowResizeUpdate(ApplicationContext &context)
		{
			ApplicationRenderer::BeginFrame(context);
			ApplicationRenderer::RenderFrame(context);
			ApplicationRenderer::RenderImGui(context);
			ApplicationRenderer::EndFrame(context);
		}
	};
}