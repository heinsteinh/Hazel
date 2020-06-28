#pragma once

#include "ApplicationInfo.h"
#include "Hazel/Window/Window.h"
#include "Hazel/Input/Input.h"
#include "Hazel/Rendering/Core/RenderApi.h"

namespace Hazel
{
	struct Context
	{
		Window Window;
		Input Input;
		RenderApiFactory &Factory;
		Drawer &Drawer;

		inline Context(const ApplicationInfo &info)
			: Window(info.WindowInfo),
			Input(Window),
			Factory(info.RenderApi.GetFactory()),
			Drawer(info.RenderApi.GetDrawer())
		{
		}
	};
}