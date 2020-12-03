#pragma once

namespace Hazel
{
	struct ProjectionInfo
	{
		float AspectRatio = 1.0f;
		float OrthographicsSize = 1.0f;
		float NearClip = -1.0f;
		float FarClip = 1.0f;
	};
}