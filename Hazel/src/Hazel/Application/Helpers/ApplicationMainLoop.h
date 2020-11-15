#pragma once

#include "ApplicationContext.h"
#include "ApplicationLayers.h"
#include "Hazel/Logging/Log.h"

namespace Hazel
{
	class ApplicationMainLoop
	{
	public:
		static inline void Run(ApplicationContext &context)
		{
			context.SetRunning(true);
			while (context.IsRunning())
			{
				Update(context);
			}
		}

		static inline void Update(ApplicationContext &context)
		{
			auto deltaTime = context.GetDeltaTime();
			Log::Trace("New frame (update time: {}ms ({}FPS)).", 1000.0f * deltaTime, 1000.0f / deltaTime);
			BeginRender(context);
			RenderNewFrame(context, deltaTime);
			EndRender(context);
		}

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
			if (context.WantRenderImGui())
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