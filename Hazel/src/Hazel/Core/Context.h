#pragma once

#include "Hazel/Window/Window.h"
#include "ApplicationSettings.h"

namespace Hazel
{
	struct Context
	{
		ApplicationSettings Settings;
		WindowProperties &Window;
		Input &Input;
		RenderApiFactory &Factory;
		Drawer &Drawer;
	};
}