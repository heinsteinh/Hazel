#pragma once

namespace Hazel
{
	struct OrthographicCameraInfo
	{
		float AspectRatio = 1.0f;
		float ZoomLevel = 1.0f;
		glm::vec2 Position{0.0f};
		float Rotation = 0.0f;

		inline glm::mat4 GetViewMatrix() const
		{
			return glm::translate(
				glm::rotate(
					glm::mat4(1.0f),
					-Rotation,
					glm::vec3(0.0f, 0.0f, 1.0f)),
				{-Position.x, -Position.y, 0.0f});
		}

		glm::mat4 GetProjectionMatrix() const
		{
			auto viewport = Rectangle::FromAspectRatio(AspectRatio, ZoomLevel);
			return glm::ortho(viewport.Left, viewport.Right, viewport.Bottom, viewport.Top);
		}
	};
}