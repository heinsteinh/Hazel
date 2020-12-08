#pragma once

#include "CameraInfo.h"

namespace Hazel
{
	class CameraProjection
	{
	public:
		static glm::vec3 GetWorldPosition(const CameraInfo &camera, const glm::vec2 &screenPosition);
		static glm::vec2 GetScreenPosition(const CameraInfo &camera, const glm::vec3 &worldPosition);

	private:
		static glm::vec4 GetViewport(const Rectangle &viewport);
	};
}