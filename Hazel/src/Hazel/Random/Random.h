#pragma once

namespace Hazel
{
	class Random
	{
	private:
		std::mt19937 engine;
		std::uniform_int_distribution<std::mt19937::result_type> distribution;

	public:
		inline Random()
			: engine(std::random_device()())
		{
		}

		inline float NextFloat()
		{
			return static_cast<float>(distribution(engine)) / static_cast<float>(std::numeric_limits<uint32_t>::max());
		}
	};
}