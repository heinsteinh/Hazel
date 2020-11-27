#pragma once

#include "ApplicationRenderer.h"

namespace Hazel
{
	class ApplicationUpdater
	{
	public:
		static void Update(ApplicationContext &context)
		{
			auto deltaTime = context.GetDeltaTime();
			Log::Trace("New frame (update time: {}ms ({}FPS)).", 1000.0f * deltaTime, 1.0f / deltaTime);
			context.GetLayers().EnableImGuiEventFilter(context.IsImGuiEventFilterEnabled());
			ApplicationRenderer::BeginRender(context);
			context.PollEvents();
			ApplicationRenderer::RenderNewFrame(context, deltaTime);
			ApplicationRenderer::EndRender(context);
		}
	};
}