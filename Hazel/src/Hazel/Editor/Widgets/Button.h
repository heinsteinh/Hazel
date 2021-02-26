#pragma once

#include "imgui.h"

namespace Hazel
{
	class Button
	{
	public:
		static bool Draw(const char *label)
		{
			return ImGui::Button(label);
		}
	};
}