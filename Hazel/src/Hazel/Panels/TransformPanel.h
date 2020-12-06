#pragma once

#include "VectorPanel.h"
#include "Hazel/Geometry/Transform.h"

namespace Hazel
{
	class TransformPanel
	{
	private:
		VectorPanel translationPanel;
		VectorPanel rotationPanel;
		VectorPanel scalePanel;

	public:
		TransformPanel()
		{
			translationPanel.SetLimits(-10.0f, 10.0f);
			rotationPanel.SetLimits(0.0f, 360.0f);
			scalePanel.SetLimits(0.0f, 10.0f);
			scalePanel.SetResetValue(1.0f);
		}

		void Draw(const char *label, Transform &transform)
		{
			ImGui::Begin(label);
			translationPanel.Draw("Translation", transform.Translation);
			auto euler = glm::degrees(glm::eulerAngles(transform.Rotation));
			rotationPanel.Draw("Rotation", euler);
			transform.Rotation = glm::quat(glm::radians(euler));
			scalePanel.Draw("Scale", transform.Scale);
			ImGui::End();
		}
	};
}