#pragma once

#include "Input.h"
#include "Hazel/Events/KeyPressEvent.h"
#include "Hazel/Events/KeyReleaseEvent.h"
#include "Hazel/Events/MouseButtonPressEvent.h"
#include "Hazel/Events/MouseButtonReleaseEvent.h"
#include "Hazel/Events/MouseMoveEvent.h"

namespace Hazel
{
	class InputUpdater
	{
	public:
		static void UpdateInput(Input &input, Event &e)
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
		}
	};
}