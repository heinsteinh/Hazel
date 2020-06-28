#include "Window.h"

#include "GLFW/glfw3.h"

#include "Helpers/GlfwLoader.h"

namespace Hazel
{
	Window::Window(const WindowInfo &info)
	{
		static GlfwLoader loader;
		Log::Debug("Window creation");
		window = glfwCreateWindow(
			static_cast<int>(info.Dimensions.Width),
			static_cast<int>(info.Dimensions.Height),
			info.Title.c_str(),
			nullptr,
			nullptr);
		glfwSwapInterval(info.VerticalSynchronization ? 1 : 0);
		Log::Debug("Window created.");
	}

	Window::~Window()
	{
		Log::Debug("Window destruction.");
		glfwDestroyWindow(window);
		Log::Debug("Window destroyed.");
	}

	Size Window::GetSize() const
	{
		int width, height;
		glfwGetWindowSize(window, &width, &height);
		return {static_cast<float>(width), static_cast<float>(height)};
	}

	bool Window::IsMinimized() const
	{
		return GetSize().IsEmpty();
	}

	void Window::SetTitle(const std::string &title)
	{
		glfwSetWindowTitle(window, title.c_str());
	}

	void Window::Resize(Size size)
	{
		glfwSetWindowSize(window, static_cast<int>(size.Width), static_cast<int>(size.Height));
	}

	void Window::SetVerticalSynchronization(bool enable)
	{
		glfwSwapInterval(enable ? 1 : 0);
	}
}