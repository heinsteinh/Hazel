#pragma once

#include "Hazel/Core/Application/ApplicationLayer.h"
#include "Hazel/Core/Events/Event.h"
#include "Hazel/Core/Input/InputManager.h"
#include "ApplicationPrivate.h"
#include "ApplicationUpdate.h"

namespace Hazel
{
	class ApplicationEvents
	{
	public:
		static void ProcessEvent(ApplicationPrivate &application, Event &e)
		{
			Log::Debug("New Event.");
			switch (e.Type)
			{
			case EventType::WindowClose:
				OnWindowClose(application, e);
				break;
			case EventType::WindowResize:
				OnWindowResize(application, e);
				break;
			case EventType::WindowRefresh:
				OnWindowRefresh(application, e);
				break;
			}
			DispatchEvent(application, e);
		}

	private:
		static void OnWindowClose(ApplicationPrivate &application, Event &e)
		{
			application.Settings.Running = false;
		}

		static void OnWindowResize(ApplicationPrivate &application, Event &e)
		{
			application.GraphicsContext->SetViewport({glm::vec2(0.0f), e.WindowSize});
		}

		static void DispatchEvent(ApplicationPrivate &application, Event &e)
		{
			application.Layers.FromTopToBottom([&](auto &layer)
			{
				if (!e.Blocked)
				{
					InputManager::OnEvent(layer.GetInput(), e);
					layer.OnEvent(e);
				}
			});
		}

		static void OnWindowRefresh(ApplicationPrivate &application, Event &e)
		{
			ApplicationUpdate::WindowRefreshUpdate(application);
		}
	};
}