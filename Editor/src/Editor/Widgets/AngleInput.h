#pragma once

#include "imgui.h"

#include "FloatInput.h"

namespace Hazel
{
	class AngleInput
	{
	private:
		FloatInput input;

	public:
		AngleInput()
		{
			input.SetLimits(-180.0f, 180.0f);
			input.SetResetValue(0.0f);
			input.SetSpeed(1.0f);
			input.SetFormat("%.2f");
		}

		bool Draw(const char *label, float &value)
		{
			auto degrees = glm::degrees(value);
			if (input.Draw(label, degrees))
			{
				value = glm::radians(degrees);
				return true;
			}
			return false;
		}
	};
}