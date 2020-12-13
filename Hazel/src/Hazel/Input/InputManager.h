#pragma once

#include "Input.h"
#include "Hazel/Events/KeyPressEvent.h"
#include "Hazel/Events/KeyReleaseEvent.h"
#include "Hazel/Events/MouseButtonPressEvent.h"
#include "Hazel/Events/MouseButtonReleaseEvent.h"
#include "Hazel/Events/MouseMoveEvent.h"
#include "Hazel/Events/MouseScrollEvent.h"

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
			e.Dispatch([&](KeyPressEvent &e)
			{
				input.SetKeyPressed(e.GetKey(), true);
			});
			e.Dispatch([&](KeyReleaseEvent &e)
			{
				input.SetKeyPressed(e.GetKey(), false);
			});
			e.Dispatch([&](MouseButtonPressEvent &e)
			{
				input.SetMouseButtonPressed(e.GetButton(), true);
			});
			e.Dispatch([&](MouseButtonReleaseEvent &e)
			{
				input.SetMouseButtonPressed(e.GetButton(), false);
			});
			e.Dispatch([&](MouseMoveEvent &e)
			{
				input.SetMousePosition(e.GetPosition());
			});
			e.Dispatch([&](MouseScrollEvent &e)
			{
				input.SetMouseScrollOffset(e.GetOffset());
			});
		}
	};
}