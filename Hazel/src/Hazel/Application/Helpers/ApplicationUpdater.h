#pragma once

#include "ApplicationEvents.h"
#include "ApplicationRenderer.h"
#include "Hazel/Logging/Log.h"

namespace Hazel
{
	class ApplicationUpdater
	{
	public:
		static inline void Init(ApplicationContext &context)
		{
			context.SetEventCallback([&](Event &e)
			{
				Log::Debug("{}.", e);
				ApplicationEvents::ProcessEvent(context, e);
			});
		}

		static inline void Update(ApplicationContext &context)
		{
			auto deltaTime = context.GetDeltaTime();
			Log::Trace("New frame (update time: {}ms ({}FPS)).", 1000.0f * deltaTime, 1000.0f / deltaTime);
			ApplicationRenderer::BeginRender(context);
			context.PollEvents();
			ApplicationRenderer::RenderNewFrame(context, deltaTime);
			ApplicationRenderer::EndRender(context);
		}
	};
}