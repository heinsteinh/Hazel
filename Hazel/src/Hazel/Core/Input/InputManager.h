#pragma once

#include "Hazel/Core/Events/Event.h"
#include "Input.h"

namespace Hazel
{
	class InputManager
	{
	public:
		static void OnNewFrame(Input &input)
		{
			input.ClearMouseScrollOffset();
		}

		static void OnEvent(Input &input, Event &e)
		{
			switch (e.Type)
			{
			case EventType::KeyPress:
				input.SetKeyPressed(e.Key, true);
				break;
			case EventType::KeyRelease:
				input.SetKeyPressed(e.Key, false);
				break;
			case EventType::MouseButtonPress:
				input.SetMouseButtonPressed(e.MouseButton, true);
				break;
			case EventType::MouseButtonRelease:
				input.SetMouseButtonPressed(e.MouseButton, false);
				break;
			case EventType::MouseMove:
				input.SetMousePosition(e.MousePosition);
				break;
			case EventType::MouseScroll:
				input.SetMouseScrollOffset(e.MouseScrollOffset);
				break;
			}
		}
	};
}