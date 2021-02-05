#pragma once

#include "ApplicationContext.h"
#include "ApplicationLayers.h"
#include "ApplicationUpdate.h"
#include "Hazel/Core/Application/Layer.h"
#include "Hazel/Core/Input/InputManager.h"
#include "Hazel/Core/Events/WindowCloseEvent.h"
#include "Hazel/Core/Events/WindowResizeEvent.h"

namespace Hazel
{
	class ApplicationEvents
	{
	public:
		static void ProcessEvent(ApplicationContext &context, ApplicationLayers &layers, Event &e)
		{
			//Log::Debug("{}.", e);
			CheckCloseEvent(context, e);
			AdjustViewport(context, e);
			DispatchEvent(layers, e);
			CheckWindowRefresh(context, layers, e);
		}

	private:
		static void CheckCloseEvent(ApplicationContext &context, Event &e)
		{
			e.Dispatch([&](WindowCloseEvent &e)
			{
				context.Settings.Running = false;
			});
		}

		static void AdjustViewport(ApplicationContext &context, Event &e)
		{
			e.Dispatch([&](WindowResizeEvent &e)
			{
				context.Window->GetGraphicsContext().SetViewport({0.0f, e.GetWidth(), 0.0f, e.GetHeight()});
			});
		}

		static void DispatchEvent(ApplicationLayers &layers, Event &e)
		{
			layers.Stack.FromTopToBottom([&](const auto &layer)
			{
				if (!e.IsHandled())
				{
					InputManager::OnEvent(layer->GetInput(), e);
					layer->OnEvent(e);
				}
			});
		}

		static void CheckWindowRefresh(ApplicationContext &context, ApplicationLayers &layers, Event &e)
		{
			e.Dispatch([&](WindowResizeEvent &e)
			{
				ApplicationUpdate::WindowResizeUpdate(context, layers);
			});
		}
	};
}