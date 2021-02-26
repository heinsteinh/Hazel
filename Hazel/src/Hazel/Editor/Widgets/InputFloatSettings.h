#pragma once

namespace Hazel
{
	struct InputFloatSettings
	{
		float Min = 0.0f;
		float Max = 0.0f;
		float Speed = 1.0f;
		const char *Format = "%.2f";
	};
}