#include "ApplicationRenderer.h"

namespace Hazel
{
	void ApplicationRenderer::BeginFrame(ApplicationContext &context)
	{
		context.ComputeDeltaTime();
		context.GetGraphicsContext().Clear();
	}

	void ApplicationRenderer::RenderFrame(ApplicationContext &context)
	{
		if (!context.GetWindow().IsMinimized())
		{
			context.GetLayers().Update();
		}
	}

	void ApplicationRenderer::RenderImGui(ApplicationContext &context)
	{
		if (context.GetSettings().ImGuiRenderEnabled)
		{
			context.GetLayers().RenderImGui();
		}
	}

	void ApplicationRenderer::EndFrame(ApplicationContext &context)
	{
		context.GetGraphicsContext().SwapBuffers();
	}
}