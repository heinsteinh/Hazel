#include "ApplicationUpdater.h"

#include "ApplicationRenderer.h"

namespace Hazel
{
	void ApplicationUpdater::Update(ApplicationContext &context)
	{
		context.ComputeDeltaTime();
		ApplicationRenderer::Clear(context);
		context.PollEvents();
		ApplicationRenderer::UpdateLayers(context);
		ApplicationRenderer::SwapBuffers(context);
	}
}