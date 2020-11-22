#pragma once

#include "ApplicationContext.h"

namespace Hazel
{
	class ApplicationRenderer
	{
	public:
		static inline void BeginRender(ApplicationContext &context)
		{
			context.GetGraphicsContext().Clear();
		}

		static inline void RenderNewFrame(ApplicationContext &context, float deltaTime)
		{
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