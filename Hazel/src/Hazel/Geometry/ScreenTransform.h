#pragma once

#include "Hazel/Camera/OrthographicCamera.h"

namespace Hazel
{
	class ScreenTransform
	{
	public:
		static glm::vec3 GetWorldPosition(const OrthographicCamera &camera, const glm::vec2 &screenPosition)
		{
			auto &windowSize = camera.GetWindowSize();
			return glm::unProject(
				glm::vec3(screenPosition, 0.0f),
				camera.GetViewMatrix(),
				camera.GetProjectionMatrix(),
				glm::vec4(0.0f, windowSize.y, windowSize.x, -windowSize.y));
		};

		static glm::vec2 GetScreenPosition(const OrthographicCamera &camera, const glm::vec3 &worldPosition)
		{
			auto &windowSize = camera.GetWindowSize();
			return glm::project(
				worldPosition,
				camera.GetViewMatrix(),
				camera.GetProjectionMatrix(),
				glm::vec4(0.0f, windowSize.y, windowSize.x, -windowSize.y));
		};
	};
}