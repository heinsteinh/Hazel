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
		bool IsRunning() const
		{
			return running;
		}

		void SetRunning(bool running)
		{
			this->running = running;
		}

		bool IsImGuiRenderEnabled() const
		{
			return imGuiRenderEnabled;
		}

		void EnableImGuiRender(bool imGuiRenderEnabled)
		{
			this->imGuiRenderEnabled = imGuiRenderEnabled;
		}

		Window &CreateApplicationWindow(const WindowInfo &info)
		{
			window = std::make_unique<Window>(info);
			eventSystem.SetWindow(*window);
			return *window;
		}

		Window &GetWindow() const
		{
			return *window;
		}

		GraphicsContext &GetGraphicsContext() const
		{
			return window->GetGraphicsContext();
		}

		void SetEventCallback(const EventSystem::Callback &callback)
		{
			eventSystem.SetCallback(callback);
		}

		void SendEvent(Event &e)
		{
			eventSystem.SendEvent(e);
		}

		void PollEvents()
		{
			eventSystem.PollEvents();
		}
	};
}