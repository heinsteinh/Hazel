#pragma once

#include "imgui.h"

namespace Hazel
{
	class DragDegrees
	{
	private:
		float minValue = -180.0f;
		float maxValue = 180.0f;
		float speed = 1.0f;

	public:
		bool Draw(const char *label, float &value)
		{
			auto degrees = glm::degrees(value);
			bool changed = ImGui::DragFloat(label, &degrees, speed, minValue, maxValue, "%.2fdeg");
			value = glm::radians(degrees);
			return changed;
		}
	};
}