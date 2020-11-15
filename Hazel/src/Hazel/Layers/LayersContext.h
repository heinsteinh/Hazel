#pragma once

#include "Hazel/Window/Window.h"
#include "Hazel/Events/EventSystem.h"

namespace Hazel
{
	class LayersContext
	{
	private:
		bool running = false;
		bool renderImGui = true;
		Window window;
		EventSystem eventSystem;

	public:
		inline LayersContext(const WindowInfo &info)
			: window(info),
			eventSystem(window)
		{
		}

		inline bool IsRunning() const
		{
			return running;
		}

		inline void SetRunning(bool running)
		{
			this->running = running;
		}

		inline bool WantRenderImGui() const
		{
			return renderImGui;
		}

		inline void EnableImGuiRendering(bool renderImGui)
		{
			this->renderImGui = renderImGui;
		}

		inline Window &GetWindow()
		{
			return window;
		}

		inline const Window &GetWindow() const
		{
			return window;
		}

		inline GraphicsContext &GetGraphicsContext() const
		{
			return window.GetGraphicsContext();
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