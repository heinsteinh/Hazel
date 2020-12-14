#pragma once

#include "Hazel/Components/TransformComponent.h"

#include "Editor/Widgets/FloatInput.h"

namespace Hazel
{
	class TransformPanel
	{
	private:
		FloatInput translationPanel;
		FloatInput rotationPanel;
		FloatInput scalePanel;

	public:
		TransformPanel()
		{
			translationPanel.SetSpeed(0.1f);
			scalePanel.SetResetValue(1.0f);
			scalePanel.SetSpeed(0.1f);
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