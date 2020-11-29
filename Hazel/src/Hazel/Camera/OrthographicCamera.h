#pragma once

#include "Hazel/Geometry/Size.h"
#include "Hazel/Geometry/Transform.h"

namespace Hazel
{
	class OrthographicCamera
	{
	private:
		glm::vec2 windowSize{1.0f};
		float zoomLevel = 1.0f;
		Transform transform;
		glm::mat4 viewMatrix{1.0f};
		glm::mat4 projectionMatrix{1.0f};
		glm::mat4 viewProjectionMatrix{1.0f};

	public:
		void SetWindowSize(const glm::vec2 &windowSize);
		void SetZoomLevel(float zoomLevel);
		void SetPosition(const glm::vec2 &position);
		void SetRotation(float rotation);

		constexpr const glm::vec2 &GetWindowSize() const
		{
			return windowSize;
		}

		constexpr float GetAspectRatio() const
		{
			return Size::GetAspectRatio(windowSize);
		}

		constexpr float GetZoomLevel() const
		{
			return zoomLevel;
		}

		constexpr glm::vec2 GetPosition() const
		{
			return transform.Position;
		}

		constexpr float GetRotation() const
		{
			return transform.Angle;
		}

		constexpr const glm::mat4 &GetViewMatrix() const
		{
			return viewMatrix;
		}

		constexpr const glm::mat4 &GetProjectionMatrix() const
		{
			return projectionMatrix;
		}

		constexpr const glm::mat4 &GetViewProjectionMatrix() const
		{
			return viewProjectionMatrix;
		}

	private:
		void RecomputeViewMatrix();
		void RecomputeProjectionMatrix();
		void RecomputeViewProjectionMatrix();
	};
}