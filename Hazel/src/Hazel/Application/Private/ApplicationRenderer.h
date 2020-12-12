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
		}

		static void RenderFrame(ApplicationContext &context)
		{
			if (!context.GetWindow().IsMinimized())
			{
				context.GetLayers().Update();
			}
		}

		static void RenderImGui(ApplicationContext &context)
		{
			if (context.GetSettings().ImGuiRenderEnabled)
			{
				context.GetLayers().RenderImGui();
			}
		}

		static void EndFrame(ApplicationContext &context)
		{
			context.GetLayers().ClearMouseScrollOffset();
			context.GetGraphicsContext().SwapBuffers();
		}
	};
}