#pragma once

#include "ApplicationContext.h"

namespace Hazel
{
	class ApplicationRenderer
	{
	public:
		static void BeginFrame(ApplicationContext &context)
		{
			context.ComputeDeltaTime();
			context.GetGraphicsContext().Clear();
			context.GetLayers().OnNewFrame();
		}

		static void RenderFrame(ApplicationContext &context)
		{
			if (!context.GetWindow().IsMinimized())
			{
				context.GetLayers().OnUpdate();
			}
		}

		static void RenderGui(ApplicationContext &context)
		{
			if (context.GetSettings().GuiRenderingEnabled)
			{
				context.GetLayers().OnGui();
			}
		}

		static void EndFrame(ApplicationContext &context)
		{
			context.GetGraphicsContext().SwapBuffers();
		}
	};
}