#pragma once

#include "Hazel/Window/WindowProperties.h"
#include "Hazel/Camera/OrthographicCamera.h"

namespace Hazel
{
	class Screen
	{
	private:
		const WindowProperties &window;
		const OrthographicCamera &camera;

	public:
		constexpr Screen(const WindowProperties &window, const OrthographicCamera &camera)
			: window(window),
			camera(camera)
		{
		}

		inline glm::vec2 GetRealPosition(const glm::vec2 &pixelPosition) const
		{
			auto [width, height] = window.GetSize();
			auto viewport = camera.GetViewport();
			auto &cameraPosition = camera.GetPosition();
			return {
				(pixelPosition.x / width - 0.5f) * viewport.GetWidth() + cameraPosition.x,
				(0.5f - pixelPosition.y / height) * viewport.GetHeight() + cameraPosition.y
			};
		};
	};
}