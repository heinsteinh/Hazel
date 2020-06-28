#pragma once

namespace Hazel
{
	struct Size
	{
		float Width = 0.0f;
		float Height = 0.0f;

		constexpr float GetAspectRatio() const
		{
			return Height ? Width / Height : 0.0f;
		}

		constexpr bool IsEmpty()
		{
			return Width == 0.0f || Height == 0.0f;
		}
	};
}