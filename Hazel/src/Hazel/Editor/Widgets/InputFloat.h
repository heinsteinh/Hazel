#pragma once

#include "glm/gtc/type_ptr.hpp"
#include "imgui.h"

#include "InputFloatSettings.h"

namespace Hazel
{
	class InputFloat
	{
	public:
		static bool Draw(const char *label, float &value, const InputFloatSettings &settings = {})
		{
			return ImGui::DragFloat(label, &value, settings.Speed, settings.Min, settings.Max, settings.Format);
		}

		static bool Draw(const char *label, glm::vec2 &value, const InputFloatSettings &settings = {})
		{
			return ImGui::DragFloat2(label, glm::value_ptr(value), settings.Speed, settings.Min, settings.Max, settings.Format);
		}

		static bool Draw(const char *label, glm::vec3 &value, const InputFloatSettings &settings = {})
		{
			return ImGui::DragFloat3(label, glm::value_ptr(value), settings.Speed, settings.Min, settings.Max, settings.Format);
		}

		static bool Draw(const char *label, glm::vec4 &value, const InputFloatSettings &settings = {})
		{
			return ImGui::DragFloat4(label, glm::value_ptr(value), settings.Speed, settings.Min, settings.Max, settings.Format);
		}
	};
}