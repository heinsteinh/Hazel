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

		const glm::vec2 &GetWindowSize() const
		{
			return windowSize;
		}

		float GetAspectRatio() const
		{
			return Size::GetAspectRatio(windowSize);
		}

		float GetZoomLevel() const
		{
			return zoomLevel;
		}

		glm::vec2 GetPosition() const
		{
			return transform.Translation;
		}

		float GetRotation() const
		{
			return glm::eulerAngles(transform.Rotation).y;
		}

		const glm::mat4 &GetViewMatrix() const
		{
			return viewMatrix;
		}

		const glm::mat4 &GetProjectionMatrix() const
		{
			return projectionMatrix;
		}

		const glm::mat4 &GetViewProjectionMatrix() const
		{
			return viewProjectionMatrix;
		}

	private:
		void RecomputeViewMatrix();
		void RecomputeProjectionMatrix();
		void RecomputeViewProjectionMatrix();
	};
}