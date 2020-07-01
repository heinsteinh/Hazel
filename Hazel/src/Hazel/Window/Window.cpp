#include "Window.h"

#include "GLFW/glfw3.h"

#include "Helpers/GlfwLoader.h"

namespace Hazel
{
	Window::Window(const WindowInfo &info)
		: window(info),
		context(info.RenderApi.GetFactory().CreateContext(window.Get())),
		imGuiContext(window.Get()),
		properties(window.Get(), info),
		eventManager(window.Get()),
		input(window.Get())
	{
		Log::Debug("New window created {} ({}x{})", info.Title, info.Size.Width, info.Size.Height);
	}

	Window::~Window()
	{
		Log::Debug("Window destroyed {}.", properties.GetTitle());
	}
}