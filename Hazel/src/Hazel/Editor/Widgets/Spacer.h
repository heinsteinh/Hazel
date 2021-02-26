#pragma once

#include "imgui.h"

namespace Hazel
{
	class Spacer
	{
	public:
		static void Draw(float offset = 0.0f, float spacing = -1.0f)
		{
			return ImGui::SameLine(offset, spacing);
		}
	};
}