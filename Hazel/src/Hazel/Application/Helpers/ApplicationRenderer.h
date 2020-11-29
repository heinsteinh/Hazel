#pragma once

#include "ApplicationContext.h"

namespace Hazel
{
	class ApplicationRenderer
	{
	public:
		static void RenderNewFrame(ApplicationContext &context, float deltaTime)
		{
			Clear(context);
			UpdateLayers(context, deltaTime);
			SwapBuffers(context);
		}

		static void Clear(ApplicationContext &context)
		{
			context.GetGraphicsContext().Clear();
		}

		static void UpdateLayers(ApplicationContext &context, float deltaTime)
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

		static void SwapBuffers(ApplicationContext &context)
		{
			context.GetGraphicsContext().SwapBuffers();
		}
	};
}