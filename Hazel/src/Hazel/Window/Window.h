#pragma once

#include "Helpers/NativeWindow.h"
#include "WindowProperties.h"
#include "EventManager.h"
#include "Hazel/Input/Input.h"
#include "Hazel/Rendering/Core/GraphicsContext.h"

namespace Hazel
{
	class Window
	{
	private:
		NativeWindow window;
		std::shared_ptr<GraphicsContext> context;
		std::shared_ptr<ImGuiDrawer> imGuiDrawer;
		WindowProperties properties;
		EventManager eventManager;
		Input input;

	public:
		Window(const WindowInfo &info = {});
		~Window();

		inline GraphicsContext &GetContext()
		{
			return *context;
		}

		inline ImGuiDrawer &GetImGuiDrawer()
		{
			return *imGuiDrawer;
		}

		constexpr WindowProperties &GetProperties()
		{
			return properties;
		}

		constexpr EventManager &GetEventManager()
		{
			return eventManager;
		}

		constexpr Input &GetInput()
		{
			return input;
		}
	};
}