#pragma once

#include "imgui.h"

namespace Hazel
{
	class ComboBox
	{
	public:
		static bool Begin(const char *label, const char *preview)
		{
			return ImGui::BeginCombo(label, preview);
		}

		static bool DrawItem(const char *label, bool &selected)
		{
			auto changed = ImGui::Selectable(label, &selected);
			if (selected)
			{
				ImGui::SetItemDefaultFocus();
			}
			return changed;
		}

		static void End()
		{
			ImGui::EndCombo();
		}
	};
}