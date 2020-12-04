#pragma once

namespace Hazel
{
	class VectorUI
	{
	private:
		float minValue = 0.0f;
		float maxValue = 0.0f;
		float resetValue = 0.0f;

	public:
		void SetLimits(float minValue, float maxValue);
		void SetResetValue(float resetValue);
		void Draw(const std::string &label, glm::vec3 &value);
	};
}