#pragma once

#include "WindowInfo.h"
#include "Hazel/Input/Key.h"
#include "Hazel/Input/MouseButton.h"

struct GLFWwindow;

namespace Hazel
{
	class Window
	{
	private:
		GLFWwindow *window;
		std::string title;
		bool verticalSynchronization;
		std::shared_ptr<GraphicsContext> graphicsContext;

	public:
		Window(const WindowInfo &info);
		~Window();

		bool IsClosed() const;
		void Close();
		const std::string &GetTitle() const;
		void SetTitle(const std::string &title);
		Size GetSize() const;
		void Resize(Size size);
		bool HasVerticalSynchonization() const;
		void SetVerticalSynchronization(bool verticalSynchronization);

		constexpr GLFWwindow *GetHandle() const
		{
			return window;
		}

		GraphicsContext &GetGraphicsContext() const
		{
			return *graphicsContext;
		}

		bool IsMinimized() const
		{
			return GetSize().IsEmpty();
		}

		float GetAspectRatio() const
		{
			return GetSize().GetAspectRatio();
		}

		float GetWidth() const
		{
			return GetSize().Width;
		}

		void SetWidth(float width)
		{
			Resize({width, GetHeight()});
		}

		float GetHeight() const
		{
			return GetSize().Height;
		}

		void SetHeight(float height)
		{
			Resize({GetWidth(), height});
		}
	};
}