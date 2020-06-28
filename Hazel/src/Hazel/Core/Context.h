#pragma once

#include "Hazel/Window/Window.h"
#include "Hazel/Input/Input.h"
#include "Hazel/Rendering/Core/RenderApi.h"

namespace Hazel
{
	struct Context
	{
		Window &Window;
		Input &Input;
		RenderApiFactory &Factory;
		Drawer &Drawer;

		inline Context(Hazel::Window &window, Hazel::Input &input, RenderApi &renderApi)
			: Window(window),
			Input(input),
			Factory(renderApi.GetFactory()),
			Drawer(renderApi.GetDrawer())
		{
		}
	};
}