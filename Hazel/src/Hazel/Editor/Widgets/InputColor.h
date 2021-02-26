#pragma once

#include "glm/gtc/type_ptr.hpp"
#include "glm/glm.hpp"
#include "imgui.h"

namespace Hazel
{
	class InputColor
	{
	public:
		static bool Draw(const char *label, glm::vec4 &value)
		{
			return ImGui::ColorEdit4("Color", glm::value_ptr(value));
		}
	};
}