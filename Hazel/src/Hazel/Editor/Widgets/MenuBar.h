#pragma once

#include "imgui.h"

namespace Hazel
{
	class MenuBar
	{
	public:
		static bool Begin()
		{
			return ImGui::BeginMenuBar();
		}

		static bool BeginMenu(const char *label, bool enabled = true)
		{
			return ImGui::BeginMenu(label, enabled);
		}

		static bool DrawItem(const char *label, const char *shortcut, bool enabled = true)
		{
			return ImGui::MenuItem(label, shortcut, nullptr, enabled);
		}

		static void EndMenu()
		{
			ImGui::EndMenu();
		}

		static void End()
		{
			ImGui::EndMenuBar();
		}
	};
}