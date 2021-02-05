#pragma once

#include "ApplicationContext.h"
#include "ApplicationLayers.h"
#include "Hazel/Core/Gui/GuiLayer.h"
#include "Hazel/Core/Input/InputManager.h"

namespace Hazel
{
	class ApplicationRenderer
	{
	public:
		static void BeginFrame(ApplicationContext &context, ApplicationLayers &layers)
		{
			context.DeltaTime = context.Chrono.Reset();
			context.Window->GetGraphicsContext().Clear();
			layers.Stack.FromBottomToTop([](const auto &layer)
			{
				InputManager::OnNewFrame(layer->GetInput());
			});
		}

		static void RenderFrame(ApplicationContext &context, ApplicationLayers &layers)
		{
			if (!context.Window->IsMinimized())
			{
				layers.Stack.FromBottomToTop([](const auto &layer)
				{
					layer->OnUpdate();
				});
			}
		}

		static void RenderGui(ApplicationContext &context, ApplicationLayers &layers)
		{
			if (layers.GuiLayer && context.Settings.GuiRenderingEnabled)
			{
				layers.GuiLayer->BeginRender();
				layers.Stack.FromBottomToTop([](const auto &layer)
				{
					layer->OnGui();
				});
				layers.GuiLayer->EndRender();
			}
		}

		static void EndFrame(ApplicationContext &context)
		{
			context.Window->GetGraphicsContext().SwapBuffers();
		}
	};
}