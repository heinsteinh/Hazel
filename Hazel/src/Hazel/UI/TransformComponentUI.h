#pragma once

#include "Vector3DControlUI.h"
#include "Hazel/Geometry/Transform.h"

namespace Hazel
{
	class TransformComponentUI
	{
	private:
		static inline const std::string translationTitle = "Translation";
		static inline const std::string rotationTitle = "Rotation";
		static inline const std::string scaleTitle = "Scale";
		Vector3DControlUI translationUI;
		Vector3DControlUI rotationUI;
		Vector3DControlUI scaleUI;

	public:
		TransformComponentUI()
		{
			translationUI.SetLimits(-10.0f, 10.0f);
			rotationUI.SetLimits(0.0f, glm::radians(360.0f));
			scaleUI.SetLimits(0.0f, 10.0f);
			scaleUI.SetResetValue(1.0f);
		}

		void Draw(const std::string &label, Transform &transform)
		{
			ImGui::Begin(label.c_str());
			translationUI.Draw(translationTitle, transform.Translation);
			glm::vec3 euler(glm::eulerAngles(transform.Rotation));
			rotationUI.Draw(rotationTitle, euler);
			transform.Rotation = glm::quat(euler);
			scaleUI.Draw(scaleTitle, transform.Scale);
			ImGui::End();
		}
	};
}