#pragma once

#include "imgui.h"

#include "Hazel/Core/Geometry/Box2D.h"
#include "Hazel/Core/Window/Window.h"

namespace Hazel
{
	class EditorViewport
	{
	public:
		static Box2D GetViewport(const Window &window)
		{
			auto bottomLeft = GetViewportPosition() - window.GetPosition();
			return {bottomLeft, bottomLeft + GetViewportSize()};
		}

		static glm::vec2 GetViewportPosition()
		{
			return GetWindowPosition() + GetCursorPosition() - GetScroll();
		}

		static glm::vec2 GetViewportSize()
		{
			auto viewportSize = ImGui::GetContentRegionAvail();
			return {viewportSize.x, viewportSize.y};
		}

		static glm::vec2 GetWindowPosition()
		{
			auto windowPosition = ImGui::GetWindowPos();
			return {windowPosition.x, windowPosition.y};
		}

		static glm::vec2 GetCursorPosition()
		{
			auto cursorPosition = ImGui::GetCursorPos();
			return {cursorPosition.x, cursorPosition.y};
		}

		static glm::vec2 GetScroll()
		{
			return {ImGui::GetScrollX(), ImGui::GetScrollY()};
		}
	};
}