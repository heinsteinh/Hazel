#pragma once

#include "glm/gtc/matrix_transform.hpp"

namespace Hazel
{
	struct OrthographicProjection
	{
		float AspectRatio = 1.0f;
		float Size = 1.0f;
		float NearClip = -1.0f;
		float FarClip = 1.0f;

		glm::mat4 ToMatrix() const
		{
			return glm::ortho(-AspectRatio * Size, AspectRatio * Size, -Size, Size, NearClip, FarClip);
		}
	};
}