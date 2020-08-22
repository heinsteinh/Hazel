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

		inline glm::vec2 GetWorldPosition(const glm::vec2 &screenPosition) const
		{
			auto [width, height] = window.GetSize();
			/*glm::unProject(
			screenPosition,
			camera.GetViewMatrix(),
			camera.GetProjectionMatrix(),
			{0.0f, 0.0f, width, height})*/
			auto viewport = camera.GetViewport();
			auto &cameraPosition = camera.GetPosition();
			return {
				(screenPosition.x / width - 0.5f) * viewport.GetWidth() + cameraPosition.x,
				(0.5f - screenPosition.y / height) * viewport.GetHeight() + cameraPosition.y
			};
		};
	};
}