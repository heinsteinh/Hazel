#pragma once

#include "Hazel/Window/Window.h"
#include "Hazel/Input/Input.h"
#include "Hazel/Rendering/Core/RenderApi.h"

namespace Hazel
{
	struct Context
	{
		WindowProperties &Window;
		Input &Input;
		RenderApiFactory &Factory;
		Drawer &Drawer;

		inline Context(Hazel::Window &window, RenderApi &renderApi)
			: Window(window.GetProperties()),
			Input(window.GetInput()),
			Factory(renderApi.GetFactory()),
			Drawer(renderApi.GetDrawer())
		{
		}
	};
}