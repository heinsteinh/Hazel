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

		inline bool IsMinimized() const
		{
			return GetSize().IsEmpty();
		}

		inline float GetAspectRatio() const
		{
			return GetSize().GetAspectRatio();
		}

		inline float GetWidth() const
		{
			return GetSize().Width;
		}

		inline float GetHeight() const
		{
			return GetSize().Height;
		}
	};
}