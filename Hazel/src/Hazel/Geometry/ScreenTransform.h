#pragma once

#include "Hazel/Window/WindowProperties.h"
#include "Hazel/Camera/OrthographicCamera.h"

namespace Hazel
{
	class ScreenTransform
	{
	private:
		const WindowProperties &window;
		const OrthographicCamera &camera;

	public:
		constexpr ScreenTransform(const WindowProperties &window, const OrthographicCamera &camera)
			: window(window),
			camera(camera)
		{
		}

		inline glm::vec3 GetWorldPosition(const glm::vec2 &screenPosition) const
		{
			auto [width, height] = window.GetSize();
			return glm::unProject(
				glm::vec3(screenPosition, 0.0f),
				camera.GetViewMatrix(),
				camera.GetProjectionMatrix(),
				glm::vec4(0.0f, height, width, -height));
		};
	};
}