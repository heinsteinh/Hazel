#pragma once

#include "Hazel/Core/ContextInfo.h"

struct GLFWwindow;

namespace Hazel
{
	class NativeWindow
	{
	private:
		GLFWwindow *window = nullptr;

	public:
		NativeWindow(const ContextInfo &info);
		~NativeWindow();

		constexpr GLFWwindow *Get() const
		{
			return window;
		}
	};
}