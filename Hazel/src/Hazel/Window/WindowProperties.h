#pragma once

#include "WindowInfo.h"

struct GLFWwindow;

namespace Hazel
{
	class WindowProperties
	{
	private:
		GLFWwindow *window = nullptr;
		std::string title;
		bool verticalSynchronization = false;

	public:
		WindowProperties(GLFWwindow *window, const WindowInfo &info);

		const std::string &GetTitle() const;
		void SetTitle(const std::string &title);
		Size GetSize() const;
		void Resize(Size size);
		bool HasVerticalSynchonization() const;
		void EnableVerticalSynchronization(bool enable);
	};
}