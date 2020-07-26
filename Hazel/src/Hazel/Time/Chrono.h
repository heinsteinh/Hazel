#pragma once

#include "Time.h"

namespace Hazel
{
	class Chrono
	{
	private:
		float referenceTime = 0.0f;

	public:
		inline Chrono()
			: referenceTime(Time::GetTime())
		{
		}

		inline float Read()
		{
			return Time::GetTime() - referenceTime;
		}

		inline float Reset()
		{
			auto time = Time::GetTime();
			auto deltaTime = time - referenceTime;
			referenceTime = time;
			return deltaTime;
		}
	};
}