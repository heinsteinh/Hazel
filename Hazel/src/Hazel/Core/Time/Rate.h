#pragma once

#include <cmath>

namespace Hazel
{
	class Rate
	{
	private:
		float accumulator = 0.0f;
		float rate = 0.0f;

	public:
		Rate() = default;

		Rate(float rate)
			: rate(rate)
		{
		}

		float GetRate() const
		{
			return rate;
		}

		int GetCount(float deltaTime)
		{
			float count = rate * deltaTime;
			float result = std::floor(count);
			accumulator += count - result;
			if (accumulator >= 1.0f)
			{
				result += 1.0f;
				accumulator -= 1.0f;
			}
			return static_cast<int>(result);
		}

		operator float() const
		{
			return rate;
		}
	};
}