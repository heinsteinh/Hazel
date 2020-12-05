#pragma once

namespace Hazel
{
	class VectorUI
	{
	private:
		float minValue = 0.0f;
		float maxValue = 0.0f;
		float resetValue = 0.0f;
		float speed = 0.1f;

	public:
		void SetLimits(float minValue, float maxValue);
		void SetResetValue(float resetValue);
		void SetSpeed(float speed);
		void Draw(const char *label, glm::vec3 &value);
	};
}