#pragma once

namespace Hazel
{
	class Random
	{
	private:
		std::mt19937 engine;
		std::uniform_int_distribution<std::mt19937::result_type> distribution;

	public:
		Random()
			: engine(std::random_device()())
		{
		}

		float GetFloat()
		{
			return static_cast<float>(distribution(engine)) / static_cast<float>(std::numeric_limits<uint32_t>::max());
		}

		float GetAngle()
		{
			return GetFloat() * 2 * glm::pi<float>();
		}

		glm::vec2 GetVector2D()
		{
			return {GetFloat() - 0.5f, GetFloat() - 0.5f};
		}
	};
}