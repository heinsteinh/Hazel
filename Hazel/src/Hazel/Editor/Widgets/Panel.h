#pragma once

#include "glm/glm.hpp"

#include "imgui.h"

namespace Hazel
{
	class Panel
	{
	public:
		static bool Begin(const char *label)
		{
			return ImGui::Begin(label);
		}

		static bool IsHovered()
		{
			return ImGui::IsWindowHovered();
		}

		static bool IsClicked()
		{
			return ImGui::IsMouseDown(ImGuiMouseButton_Left) && ImGui::IsWindowHovered();
		}

		static float GetWidth()
		{
			return ImGui::GetWindowWidth();
		}

		static float GetHeight()
		{
			return ImGui::GetWindowHeight();
		}

		static glm::vec2 GetSize()
		{
			return {GetWidth(), GetHeight()};
		}

		static void End()
		{
			ImGui::End();
		}
	};
}