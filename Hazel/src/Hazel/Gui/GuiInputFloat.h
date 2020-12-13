#pragma once

#include "imgui.h"

namespace Hazel
{
	class GuiInputFloat
	{
	private:
		float minValue = 0.0f;
		float maxValue = 0.0f;
		float resetValue = 0.0f;
		float speed = 1.0f;
		std::string format = "%.2f";

	public:
		void SetLimits(float minValue, float maxValue)
		{
			this->minValue = minValue;
			this->maxValue = maxValue;
		}

		void SetResetValue(float resetValue)
		{
			this->resetValue = resetValue;
		}

		void SetSpeed(float speed)
		{
			this->speed = speed;
		}

		void SetFormat(const std::string &format)
		{
			this->format = format;
		}

		bool Draw(const char *label, float &value)
		{
			return ImGui::DragFloat(label, &value, speed, minValue, maxValue, format.c_str());
		}

		bool Draw(const char *label, glm::vec2 &value)
		{
			return ImGui::DragFloat2(label, glm::value_ptr(value), speed, minValue, maxValue, format.c_str());
		}

		bool Draw(const char *label, glm::vec3 &value)
		{
			return ImGui::DragFloat3(label, glm::value_ptr(value), speed, minValue, maxValue, format.c_str());
		}

		bool Draw(const char *label, glm::vec4 &value)
		{
			return ImGui::DragFloat4(label, glm::value_ptr(value), speed, minValue, maxValue, format.c_str());
		}
	};
}