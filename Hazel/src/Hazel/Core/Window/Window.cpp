#include "Window.h"

#include "GLFW/glfw3.h"

#include "Hazel/Core/Logging/Log.h"
#include "Private/GlfwLoader.h"

namespace Hazel
{
	Window::Window(const WindowInfo &info)
		: title(info.Title)
	{
		static GlfwLoader glfwLoader;
		window = glfwCreateWindow(
			static_cast<int>(info.Resolution.x),
			static_cast<int>(info.Resolution.y),
			info.Title.c_str(),
			nullptr,
			nullptr);
		graphicsContext = info.GraphicsApi->CreateContext(window);
		SetVerticalSynchronization(info.VerticalSynchronization);
		Log::Debug("New window created {}", title);
	}

	Window::~Window()
	{
		glfwDestroyWindow(window);
		Log::Debug("Window destroyed {}.", title);
	}

	bool Window::IsClosed() const
	{
		return glfwWindowShouldClose(window);
	}

	void Window::Close()
	{
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}

	const std::string &Window::GetTitle() const
	{
		return title;
	}

	void Window::SetTitle(const std::string &title)
	{
		this->title = title;
		glfwSetWindowTitle(window, title.c_str());
	}

	glm::vec2 Window::GetSize() const
	{
		int width, height;
		glfwGetWindowSize(window, &width, &height);
		return {static_cast<float>(width), static_cast<float>(height)};
	}

	void Window::Resize(const glm::vec2 &size)
	{
		glfwSetWindowSize(window, static_cast<int>(size.x), static_cast<int>(size.y));
	}

	glm::vec2 Window::GetPosition() const
	{
		int x, y;
		glfwGetWindowPos(window, &x, &y);
		return {static_cast<float>(x), static_cast<float>(y)};
	}

	void Window::SetPosition(const glm::vec2 &position)
	{
		glfwSetWindowPos(window, static_cast<int>(position.x), static_cast<int>(position.y));
	}

	bool Window::HasVerticalSynchonization() const
	{
		return verticalSynchronization;
	}

	void Window::SetVerticalSynchronization(bool verticalSynchronization)
	{
		this->verticalSynchronization = verticalSynchronization;
		glfwSwapInterval(verticalSynchronization ? 1 : 0);
	}
}