#pragma once

#include "Hazel/Window/WindowInfo.h"

struct GLFWwindow;

namespace Hazel
{
	class NativeWindow
	{
	private:
		GLFWwindow *window = nullptr;

	public:
		NativeWindow(const WindowInfo &info);
		~NativeWindow();

		constexpr GLFWwindow *Get() const
		{
			return window;
		}
	};
}