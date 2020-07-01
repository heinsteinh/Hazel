#pragma once

#include "Hazel/Window/WindowInfo.h"

struct GLFWwindow;

namespace Hazel
{
	class GlfwWindow
	{
	private:
		GLFWwindow *window = nullptr;

	public:
		GlfwWindow(const WindowInfo &info);
		~GlfwWindow();

		constexpr GLFWwindow *Get() const
		{
			return window;
		}
	};
}