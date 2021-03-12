#pragma once

#include "WindowInfo.h"
#include "Hazel/Core/Geometry/Size.h"
#include "Private/GlfwEventReceiver.h"

struct GLFWwindow;

namespace Hazel
{
	class Window
	{
	private:
		GLFWwindow *window;
		std::string title;
		GlfwEventReceiver eventReceiver;

	public:
		Window(const WindowInfo &info);
		~Window();

		bool IsClosed() const;
		void Close();
		const std::string &GetTitle() const;
		void SetTitle(const std::string &title);
		glm::vec2 GetSize() const;
		void Resize(const glm::vec2 &size);
		glm::vec2 GetPosition() const;
		void SetPosition(const glm::vec2 &position);
		void SetEventCallback(const EventCallback &callback);

		GLFWwindow *GetHandle() const
		{
			return window;
		}

		bool IsMinimized() const
		{
			return Size::IsEmpty(GetSize());
		}

		float GetAspectRatio() const
		{
			return Size::GetAspectRatio(GetSize());
		}

		float GetWidth() const
		{
			return GetSize().x;
		}

		void SetWidth(float width)
		{
			Resize({width, GetHeight()});
		}

		float GetHeight() const
		{
			return GetSize().y;
		}

		void SetHeight(float height)
		{
			Resize({GetWidth(), height});
		}
	};
}