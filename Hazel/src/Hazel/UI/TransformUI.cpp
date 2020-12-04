#include "TransformUI.h"

#include "imgui.h"

namespace Hazel
{
	TransformUI::TransformUI()
	{
		translationUI.SetLimits(-10.0f, 10.0f);
		rotationUI.SetLimits(0.0f, 360.0f);
		scaleUI.SetLimits(0.0f, 10.0f);
		scaleUI.SetResetValue(1.0f);
	}

	void TransformUI::Draw(const std::string &label, Transform &transform)
	{
		ImGui::Begin(label.c_str());
		translationUI.Draw(translationTitle, transform.Translation);
		auto euler = glm::degrees(glm::eulerAngles(transform.Rotation));
		rotationUI.Draw(rotationTitle, euler);
		transform.Rotation = glm::quat(glm::radians(euler));
		scaleUI.Draw(scaleTitle, transform.Scale);
		ImGui::End();
	}
}