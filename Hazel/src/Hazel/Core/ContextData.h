#pragma once

#include "Hazel/Window/Window.h"
#include "Hazel/Input/Input.h"
#include "Hazel/Events/EventManager.h"
#include "Hazel/Layers/LayerManager.h"
#include "ApplicationInfo.h"

namespace Hazel
{
	struct ContextData
	{
		Window Window;
		Input Input;
		EventManager EventManager;
		LayerManager LayerManager;

		inline ContextData(const ApplicationInfo &info)
			: Window(info.WindowInfo),
			Input(Window.GetHandle()),
			EventManager(Window.GetHandle()),
			LayerManager(Window)
		{
		}
	};
}