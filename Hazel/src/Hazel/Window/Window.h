#pragma once

#include "WindowInfo.h"
#include "Hazel/Utils/Size.h"

struct GLFWwindow;

namespace Hazel
{
	class Window
	{
	private:
		GLFWwindow *window = nullptr;

	public:
		Window(const WindowInfo &info = {});
		~Window();

		Size GetSize() const;
		bool IsMinimized() const;
		void SetTitle(const std::string &title);
		void Resize(Size size);
		void SetVerticalSynchronization(bool enable);

		constexpr GLFWwindow *GetHandle() const
		{
			return window;
		}
	};
}