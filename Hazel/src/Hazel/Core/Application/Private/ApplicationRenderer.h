#pragma once

#include "ApplicationContext.h"

namespace Hazel
{
	class ApplicationRenderer
	{
	public:
		static void BeginFrame(ApplicationContext &context)
		{
			context.DeltaTime = context.Chrono.Reset();
			context.Window->GetGraphicsContext().Clear();
			context.Layers.OnNewFrame();
		}

		static void RenderFrame(ApplicationContext &context)
		{
			if (!context.Window->IsMinimized())
			{
				context.Layers.OnUpdate();
			}
		}

		static void RenderGui(ApplicationContext &context)
		{
			if (context.Settings.GuiRenderingEnabled)
			{
				context.Layers.OnGui();
			}
		}

		static void EndFrame(ApplicationContext &context)
		{
			context.Window->GetGraphicsContext().SwapBuffers();
		}
	};
}