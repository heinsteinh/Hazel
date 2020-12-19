#pragma once

#include "Time.h"

namespace Hazel
{
	class Chrono
	{
	private:
		float referenceTime = 0.0f;

	public:
		Chrono()
			: referenceTime(Time::GetTime())
		{
		}

		float Read()
		{
			return Time::GetTime() - referenceTime;
		}

		float Reset()
		{
			auto time = Time::GetTime();
			auto deltaTime = time - referenceTime;
			referenceTime = time;
			return deltaTime;
		}
	};
}