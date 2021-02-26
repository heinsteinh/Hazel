#pragma once

#include "imgui.h"

namespace Hazel
{
	class CheckBox
	{
	public:
		static bool Draw(const char *label, bool &checked)
		{
			return ImGui::Checkbox(label, &checked);
		}
	};
}