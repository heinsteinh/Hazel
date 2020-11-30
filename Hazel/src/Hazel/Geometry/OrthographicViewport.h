#pragma once

namespace Hazel
{
	struct OrthographicViewport
	{
		float AspectRatio = 1.0f;
		float Size = 1.0f;
		float NearClip = -1.0f;
		float FarClip = 1.0f;
	};
}