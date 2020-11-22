#pragma once

#include "ApplicationContext.h"
#include "Hazel/Logging/Log.h"

namespace Hazel
{
	class ApplicationUpdater
	{
	public:
		static inline void Update(ApplicationContext &context)
		{
			auto deltaTime = context.GetDeltaTime();
			Log::Trace("New frame (update time: {}ms ({}FPS)).", 1000.0f * deltaTime, 1000.0f / deltaTime);
			BeginRender(context);
			RenderNewFrame(context, deltaTime);
			EndRender(context);
		}

	private:
		static inline void BeginRender(ApplicationContext &context)
		{
			context.GetGraphicsContext().Clear();
		}

		static inline void RenderNewFrame(ApplicationContext &context, float deltaTime)
		{
			context.PollEvents();
			auto &layers = context.GetLayers();
			if (!context.GetWindow().IsMinimized())
			{
				layers.UpdateLayers(deltaTime);
			}
			if (context.IsImGuiRenderEnabled())
			{
				layers.RenderImGui();
			}
		}

		static inline void EndRender(ApplicationContext &context)
		{
			context.GetGraphicsContext().SwapBuffers();
		}
	};
}