#pragma once

#include "Time.h"

namespace Hazel
{
	class Chrono
	{
	private:
		double referenceTime = 0.0;

	public:
		Chrono()
			: referenceTime(Time::GetTime())
		{
		}

		float Read()
		{
			return static_cast<float>(Time::GetTime() - referenceTime);
		}

		float Reset()
		{
			auto time = Time::GetTime();
			auto deltaTime = time - referenceTime;
			referenceTime = time;
			return static_cast<float>(deltaTime);
		}
	};
}