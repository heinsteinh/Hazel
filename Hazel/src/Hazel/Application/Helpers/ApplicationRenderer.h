#pragma once

#include "ApplicationContext.h"

namespace Hazel
{
	class ApplicationRenderer
	{
	public:
		static void BeginRender(ApplicationContext &context)
		{
			context.GetGraphicsContext().Clear();
		}

		static void RenderNewFrame(ApplicationContext &context, float deltaTime)
		{
			auto &layers = context.GetLayers();
			if (!context.GetWindow().IsMinimized())
			{
				layers.UpdateLayers(deltaTime);
			}
			if (context.GetSettings().ImGuiRenderEnabled)
			{
				layers.RenderImGui();
			}
		}

		static void EndRender(ApplicationContext &context)
		{
			context.GetGraphicsContext().SwapBuffers();
		}
	};
}