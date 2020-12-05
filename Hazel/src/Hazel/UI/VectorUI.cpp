#include "VectorUI.h"

#include "imgui.h"
#include "imgui_internal.h"

namespace Hazel
{
	void VectorUI::SetLimits(float minValue, float maxValue)
	{
		this->minValue = minValue;
		this->maxValue = maxValue;
	}

	void VectorUI::SetResetValue(float resetValue)
	{
		this->resetValue = resetValue;
	}

	void VectorUI::SetSpeed(float speed)
	{
		this->speed = speed;
	}

	void VectorUI::Draw(const char *label, glm::vec3 &value)
	{
		ImGui::DragFloat3(label, glm::value_ptr(value), speed, minValue, maxValue, "%.2f");
	}
}