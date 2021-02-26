#pragma once

#include "imgui.h"

#include "InputFloat.h"

namespace Hazel
{
	class InputAngle
	{
	public:
		static bool Draw(const char *label, float &value)
		{
			auto degrees = glm::degrees(value);
			if (InputFloat::Draw(label, degrees, GetSettings()))
			{
				value = glm::radians(degrees);
				return true;
			}
			return false;
		}

		static bool Draw(const char *label, glm::quat &value)
		{
			auto euler = glm::degrees(glm::eulerAngles(value));
			if (InputFloat::Draw(label, euler, GetSettings()))
			{
				value = glm::quat(glm::radians(euler));
				return true;
			}
			return false;
		}

	private:
		static InputFloatSettings GetSettings()
		{
			InputFloatSettings settings;
			settings.Min = -180.0f;
			settings.Max = 180.0f;
			return settings;
		}
	};
}