#pragma once

#include "Hazel/Gui/GuiInputFloat.h"
#include "Hazel/Components/TransformComponent.h"

namespace Hazel
{
	class TransformPanel
	{
	private:
		GuiInputFloat translationPanel;
		GuiInputFloat rotationPanel;
		GuiInputFloat scalePanel;

	public:
		TransformPanel()
		{
			translationPanel.SetLimits(-10.0f, 10.0f);
			rotationPanel.SetLimits(0.0f, 360.0f);
			scalePanel.SetLimits(0.0f, 10.0f);
			scalePanel.SetResetValue(1.0f);
		}

		void SetTranslationLimits(float minValue, float maxValue)
		{
			translationPanel.SetLimits(minValue, maxValue);
		}

		void SetRotationLimits(float minValue, float maxValue)
		{
			rotationPanel.SetLimits(minValue, maxValue);
		}

		void SetScaleLimits(float minValue, float maxValue)
		{
			scalePanel.SetLimits(minValue, maxValue);
		}

		void Draw(TransformComponent &transform)
		{
			Draw(transform.Transform);
		}

		void Draw(Transform &transform)
		{
			translationPanel.Draw("Translation", transform.Translation);
			auto euler = glm::degrees(glm::eulerAngles(transform.Rotation));
			if (rotationPanel.Draw("Rotation", euler))
			{
				transform.Rotation = glm::quat(glm::radians(euler));
			}
			scalePanel.Draw("Scale", transform.Scale);
		}
	};
}