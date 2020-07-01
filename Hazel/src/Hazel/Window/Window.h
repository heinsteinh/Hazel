#pragma once

#include "Helpers/GlfwWindow.h"
#include "WindowProperties.h"
#include "Hazel/Events/EventManager.h"
#include "Hazel/Input/Input.h"
#include "Hazel/Rendering/Core/GraphicsContext.h"
#include "Hazel/ImGui/ImGuiDrawingContext.h"

namespace Hazel
{
	class Window
	{
	private:
		GlfwWindow window;
		std::shared_ptr<GraphicsContext> context;
		ImGuiDrawingContext imGuiContext;
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

		constexpr ImGuiDrawingContext &GetImGuiContext()
		{
			return imGuiContext;
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