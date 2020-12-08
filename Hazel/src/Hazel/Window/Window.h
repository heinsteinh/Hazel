#pragma once

#include "WindowInfo.h"
#include "Hazel/Input/Key.h"
#include "Hazel/Input/MouseButton.h"
#include "Hazel/Geometry/Size.h"

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
		glm::vec2 GetSize() const;
		void Resize(const glm::vec2 &size);
		glm::vec2 GetPosition() const;
		void SetPosition(const glm::vec2 &position);
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