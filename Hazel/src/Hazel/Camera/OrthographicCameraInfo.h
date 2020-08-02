#pragma once

namespace Hazel
{
	struct OrthographicCameraInfo
	{
		float AspectRatio = 1.0f;
		float ZoomLevel = 1.0f;
		glm::vec2 Position{0.0f};
		float Rotation = 0.0f;

		constexpr Rectangle GetViewport() const
		{
			return Rectangle::FromAspectRatio(AspectRatio, ZoomLevel);
		}

		inline glm::mat4 GetViewMatrix() const
		{
			return glm::inverse(
				glm::translate(glm::mat4(1.0f), {Position.x, Position.y, 0.0f})
				* glm::rotate(glm::mat4(1.0f), Rotation, {0.0f, 0.0f, 1.0f}));
		}

		inline glm::mat4 GetProjectionMatrix() const
		{
			auto viewport = GetViewport();
			return glm::ortho(viewport.Left, viewport.Right, viewport.Bottom, viewport.Top, -1.0f, 1.0f);
		}
	};
}