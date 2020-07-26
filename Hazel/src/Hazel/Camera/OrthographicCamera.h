#pragma once

#include "Hazel/Geometry/Rectangle.h"

namespace Hazel
{
	class OrthographicCamera
	{
	private:
		glm::vec2 position{0.0f};
		float rotation = 0.0f;
		Rectangle viewport = {-1.0f, 1.0f, -1.0f, 1.0f};

	public:
		constexpr OrthographicCamera() = default;

		constexpr OrthographicCamera(float aspectRatio, float zoomLevel = 1.0f)
			: viewport(Rectangle::FromAspectRatio(aspectRatio, zoomLevel))
		{
		}

		constexpr const glm::vec2 &GetPosition() const
		{
			return position;
		}

		constexpr void SetPosition(const glm::vec2 &position)
		{
			this->position = position;
		}

		constexpr float GetRotation() const
		{
			return rotation;
		}

		constexpr void SetRotation(float rotation)
		{
			this->rotation = rotation;
		}

		constexpr float GetAspectRatio() const
		{
			return viewport.GetAspectRatio();
		}

		constexpr void SetAspectRatio(float aspectRatio)
		{
			viewport = Rectangle::FromAspectRatio(aspectRatio, GetZoomLevel());
		}

		constexpr float GetZoomLevel() const
		{
			return viewport.GetHeight() / 2.0f;
		}

		constexpr void SetZoomLevel(float zoomLevel)
		{
			viewport = Rectangle::FromAspectRatio(GetAspectRatio(), zoomLevel);
		}

		inline glm::mat4 GetViewMatrix() const
		{
			return glm::translate(
				glm::rotate(
					glm::mat4(1.0f),
					-rotation,
					glm::vec3(0.0f, 0.0f, 1.0f)),
				{-position.x, -position.y, 0.0f});
		}

		inline glm::mat4 GetProjectionMatrix() const
		{
			return glm::ortho(viewport.Left, viewport.Right, viewport.Bottom, viewport.Top);
		}

		inline glm::mat4 GetViewProjectionMatrix() const
		{
			return GetProjectionMatrix() * GetViewMatrix();
		}
	};
}