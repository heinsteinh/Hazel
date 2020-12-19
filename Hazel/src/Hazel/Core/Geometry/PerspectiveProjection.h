#pragma once

namespace Hazel
{
	struct PerspectiveProjection
	{
		float AspectRatio = 1.0f;
		float VerticalFov = glm::radians(45.0f);
		float NearClip = 0.01f;
		float FarClip = 1000.0f;

		glm::mat4 ToMatrix() const
		{
			return glm::perspective(VerticalFov, AspectRatio, NearClip, FarClip);
		}
	};
}