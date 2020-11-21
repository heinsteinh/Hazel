#pragma once

#include "Hazel/Window/Window.h"
#include "Hazel/Camera/OrthographicCamera.h"

namespace Hazel
{
	class ScreenTransform
	{
	private:
		const Window *window = nullptr;
		const OrthographicCamera *camera = nullptr;

	public:
		ScreenTransform() = default;

		constexpr ScreenTransform(const Window &window, const OrthographicCamera &camera)
			: window(&window),
			camera(&camera)
		{
		}

		inline glm::vec3 GetWorldPosition(const glm::vec2 &screenPosition) const
		{
			auto [width, height] = window->GetSize();
			return glm::unProject(
				glm::vec3(screenPosition, 0.0f),
				camera->GetViewMatrix(),
				camera->GetProjectionMatrix(),
				glm::vec4(0.0f, height, width, -height));
		};

		inline glm::vec2 GetScreenPosition(const glm::vec3 &worldPosition) const
		{
			auto [width, height] = window->GetSize();
			return glm::project(
				worldPosition,
				camera->GetViewMatrix(),
				camera->GetProjectionMatrix(),
				glm::vec4(0.0f, height, width, -height));
		};
	};
}