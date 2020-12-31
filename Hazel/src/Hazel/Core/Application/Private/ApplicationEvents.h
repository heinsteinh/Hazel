#pragma once

#include "ApplicationContext.h"
#include "ApplicationLayers.h"
#include "ApplicationUpdate.h"
#include "Hazel/Core/Application/Layer.h"
#include "Hazel/Core/Utils/Reversed.h"
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
			e.Dispatch([&](WindowCloseEvent &e)
			{
				context.Settings.Running = false;
			});
			e.Dispatch([&](WindowResizeEvent &e)
			{
				context.Window->GetGraphicsContext().SetViewport({0.0f, e.GetWidth(), 0.0f, e.GetHeight()});
			});
			for (const auto &layer : Reversed(layers.Stack))
			{
				if (e.IsHandled())
				{
					break;
				}
				InputManager::OnEvent(layer->GetInput(), e);
				layer->OnEvent(e);
			}
			e.Dispatch([&](WindowResizeEvent &e)
			{
				ApplicationUpdate::WindowResizeUpdate(context, layers);
			});
		}
	};
}