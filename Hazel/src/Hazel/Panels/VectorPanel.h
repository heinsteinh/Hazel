#pragma once

#include "imgui.h"

namespace Hazel
{
	class VectorPanel
	{
	private:
		float minValue = 0.0f;
		float maxValue = 0.0f;
		float resetValue = 0.0f;
		float speed = 0.1f;

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

		void Draw(const char *label, glm::vec3 &value)
		{
			ImGui::DragFloat3(label, glm::value_ptr(value), speed, minValue, maxValue, "%.2f");
		}
	};
}