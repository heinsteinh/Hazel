#pragma once

#include "Hazel/Core/Events/EventSystem.h"
#include "ApplicationPrivate.h"
#include "ApplicationRenderer.h"

namespace Hazel
{
	class ApplicationUpdate
	{
	public:
		static void MainLoopUpdate(ApplicationPrivate &application)
		{
			ApplicationRenderer::BeginFrame(application);
			EventSystem::PollEvents();
			ApplicationRenderer::RenderFrame(application);
			ApplicationRenderer::RenderGui(application);
			ApplicationRenderer::EndFrame(application);
		}

		static void WindowRefreshUpdate(ApplicationPrivate &application)
		{
			ApplicationRenderer::BeginFrame(application);
			ApplicationRenderer::RenderFrame(application);
			ApplicationRenderer::RenderGui(application);
			ApplicationRenderer::EndFrame(application);
		}
	};
}