#pragma once

#include "ApplicationPrivate.h"
#include "Hazel/Core/Gui/GuiLayer.h"
#include "Hazel/Core/Input/InputManager.h"

namespace Hazel
{
	class ApplicationRenderer
	{
	public:
		static void BeginFrame(ApplicationPrivate &application)
		{
			application.DeltaTime = application.Chrono.Reset();
			application.GraphicsContext->Clear();
			application.Layers.FromBottomToTop([](auto &layer)
			{
				InputManager::OnNewFrame(layer.GetInput());
			});
		}

		static void RenderFrame(ApplicationPrivate &application)
		{
			if (!application.Window->IsMinimized())
			{
				application.Layers.FromBottomToTop([](auto &layer)
				{
					layer.OnUpdate();
				});
			}
		}

		static void RenderGui(ApplicationPrivate &application)
		{
			if (application.GuiLayer && application.Settings.GuiRenderingEnabled)
			{
				application.GuiLayer->BeginRender();
				application.Layers.FromBottomToTop([](auto &layer)
				{
					layer.OnGui();
				});
				application.GuiLayer->EndRender();
			}
		}

		static void EndFrame(ApplicationPrivate &application)
		{
			application.GraphicsContext->SwapBuffers();
		}
	};
}