#pragma once

#include "glm/gtc/matrix_transform.hpp"

namespace Hazel
{
	struct OrthographicProjection
	{
		float AspectRatio = 1.0f;
		float Size = 2.0f;
		float NearClip = -1.0f;
		float FarClip = 1.0f;

		glm::mat4 ToMatrix() const
		{
			auto size = Size / 2.0f;
			return glm::ortho(-AspectRatio * size, AspectRatio * size, -size, size, NearClip, FarClip);
		}
	};
}