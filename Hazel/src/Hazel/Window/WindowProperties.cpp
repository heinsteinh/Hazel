#include "WindowProperties.h"

#include "GLFW/glfw3.h"

namespace Hazel
{
	WindowProperties::WindowProperties(GLFWwindow *window, const WindowInfo &info)
		: window(window),
		title(info.Title)
	{
		EnableVerticalSynchronization(info.VerticalSynchronization);
	}

	const std::string &WindowProperties::GetTitle() const
	{
		return title;
	}

	void WindowProperties::SetTitle(const std::string &title)
	{
		this->title = title;
		glfwSetWindowTitle(window, title.c_str());
	}

	Size WindowProperties::GetSize() const
	{
		int width, height;
		glfwGetWindowSize(window, &width, &height);
		return {static_cast<float>(width), static_cast<float>(height)};
	}

	void WindowProperties::Resize(Size size)
	{
		glfwSetWindowSize(window, static_cast<int>(size.Width), static_cast<int>(size.Height));
	}

	bool WindowProperties::HasVerticalSynchonizationEnabled() const
	{
		return verticalSynchronization;
	}

	void WindowProperties::EnableVerticalSynchronization(bool enable)
	{
		verticalSynchronization = enable;
		glfwSwapInterval(verticalSynchronization ? 1 : 0);
	}
}