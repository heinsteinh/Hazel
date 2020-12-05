#include "ApplicationRenderer.h"

namespace Hazel
{
	void ApplicationRenderer::RenderNewFrame(ApplicationContext &context)
	{
		Clear(context);
		UpdateLayers(context);
		SwapBuffers(context);
	}

	void ApplicationRenderer::Clear(ApplicationContext &context)
	{
		context.GetGraphicsContext().Clear();
	}

	void ApplicationRenderer::UpdateLayers(ApplicationContext &context)
	{
		auto &layers = context.GetLayers();
		if (!context.GetWindow().IsMinimized())
		{
			layers.UpdateLayers();
		}
		if (context.GetSettings().ImGuiRenderEnabled)
		{
			layers.RenderImGui();
		}
	}

	void ApplicationRenderer::SwapBuffers(ApplicationContext &context)
	{
		context.GetGraphicsContext().SwapBuffers();
	}
}