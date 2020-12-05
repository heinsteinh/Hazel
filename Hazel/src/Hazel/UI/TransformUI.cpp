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

	void TransformUI::Draw(const char *label, Transform &transform)
	{
		ImGui::Begin(label);
		translationUI.Draw("Translation", transform.Translation);
		auto euler = glm::degrees(glm::eulerAngles(transform.Rotation));
		rotationUI.Draw("Rotation", euler);
		transform.Rotation = glm::quat(glm::radians(euler));
		scaleUI.Draw("Scale", transform.Scale);
		ImGui::End();
	}
}