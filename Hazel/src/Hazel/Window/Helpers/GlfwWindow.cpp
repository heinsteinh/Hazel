#include "GlfwWindow.h"

#include "GLFW/glfw3.h"

#include "GlfwLoader.h"

namespace Hazel
{
	GlfwWindow::GlfwWindow(const WindowInfo &info)
	{
		static GlfwLoader loader;
		window = glfwCreateWindow(
			static_cast<int>(info.Size.Width),
			static_cast<int>(info.Size.Height),
			info.Title.c_str(),
			nullptr,
			nullptr);
	}

	GlfwWindow::~GlfwWindow()
	{
		glfwDestroyWindow(window);
	}
}