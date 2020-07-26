#pragma once

#include "Helpers/NativeWindow.h"
#include "WindowProperties.h"
#include "EventManager.h"
#include "Hazel/Input/Input.h"
#include "Hazel/Rendering/Core/GraphicsContext.h"
#include "Hazel/ImGui/ImGuiContext.h"

namespace Hazel
{
	class Window
	{
	private:
		NativeWindow window;
		std::shared_ptr<GraphicsContext> context;
		ImGuiContext imGuiContext;
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

		constexpr ImGuiContext &GetImGuiContext()
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