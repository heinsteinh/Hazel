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
			for (const auto &layer : layers.Stack)
			{
				InputManager::OnNewFrame(layer->GetInput());
			}
		}

		static void RenderFrame(ApplicationContext &context, ApplicationLayers &layers)
		{
			if (!context.Window->IsMinimized())
			{
				for (const auto &layer : layers.Stack)
				{
					layer->OnUpdate();
				}
			}
		}

		static void RenderGui(ApplicationContext &context, ApplicationLayers &layers)
		{
			if (layers.GuiLayer && context.Settings.GuiRenderingEnabled)
			{
				layers.GuiLayer->BeginRender();
				for (const auto &layer : layers.Stack)
				{
					layer->OnGui();
				}
				layers.GuiLayer->EndRender();
			}
		}

		static void EndFrame(ApplicationContext &context)
		{
			context.Window->GetGraphicsContext().SwapBuffers();
		}
	};
}