#include "NativeWindow.h"

#include "GLFW/glfw3.h"

#include "GlfwLoader.h"

namespace Hazel
{
	NativeWindow::NativeWindow(const ContextInfo &info)
	{
		static GlfwLoader loader;
		window = glfwCreateWindow(
			static_cast<int>(info.Resolution.Width),
			static_cast<int>(info.Resolution.Height),
			info.Title.c_str(),
			nullptr,
			nullptr);
	}

	NativeWindow::~NativeWindow()
	{
		glfwDestroyWindow(window);
	}
}