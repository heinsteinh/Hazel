#pragma once

#include "imgui.h"

namespace Hazel
{
	class GuiConfiguration
	{
	public:
		static void SetDefaultConfiguration()
		{
			ImGui::GetIO().ConfigFlags = GetDefaultFlags();
		}

		static int GetDefaultFlags()
		{
			return ImGuiConfigFlags_NavEnableKeyboard
				| ImGuiConfigFlags_DockingEnable
				| ImGuiConfigFlags_ViewportsEnable;
		}
	};
}