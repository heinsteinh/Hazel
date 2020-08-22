#include "Window.h"

#include "GLFW/glfw3.h"

#include "Helpers/GlfwLoader.h"

namespace Hazel
{
	Window::Window(const ContextInfo &info)
		: window(info),
		context(info.RenderApi.GetFactory().CreateContext(window.Get())),
		imGuiDrawer(info.RenderApi.GetFactory().CreateImGuiDrawer(window.Get())),
		properties(window.Get(), info),
		eventManager(window.Get()),
		input(window.Get())
	{
		Log::Debug("New window created {} ({}x{})", info.Title, info.Resolution.Width, info.Resolution.Height);
	}

	Window::~Window()
	{
		Log::Debug("Window destroyed {}.", properties.GetTitle());
	}
}