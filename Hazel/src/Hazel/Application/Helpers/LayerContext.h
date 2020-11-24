#pragma once

#include "Hazel/Window/Window.h"
#include "Hazel/Events/EventSystem.h"

namespace Hazel
{
	class LayerContext
	{
	private:
		bool running = false;
		bool imGuiRenderEnabled = true;
		std::unique_ptr<Window> window;
		EventSystem eventSystem;

	public:
		inline bool IsRunning() const
		{
			return running;
		}

		inline void SetRunning(bool running)
		{
			this->running = running;
		}

		inline bool IsImGuiRenderEnabled() const
		{
			return imGuiRenderEnabled;
		}

		inline void EnableImGuiRender(bool imGuiRenderEnabled)
		{
			this->imGuiRenderEnabled = imGuiRenderEnabled;
		}

		inline Window &CreateApplicationWindow(const WindowInfo &info)
		{
			window = std::make_unique<Window>(info);
			eventSystem.SetWindow(*window);
			return *window;
		}

		inline Window &GetWindow() const
		{
			return *window;
		}

		inline GraphicsContext &GetGraphicsContext() const
		{
			return window->GetGraphicsContext();
		}

		inline void SetEventCallback(const EventSystem::Callback &callback)
		{
			eventSystem.SetCallback(callback);
		}

		inline void SendEvent(Event &e)
		{
			eventSystem.SendEvent(e);
		}

		inline void PollEvents()
		{
			eventSystem.PollEvents();
		}
	};
}