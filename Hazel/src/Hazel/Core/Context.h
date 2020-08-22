#pragma once

#include "Hazel/Window/WindowProperties.h"
#include "Hazel/Input/Input.h"
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