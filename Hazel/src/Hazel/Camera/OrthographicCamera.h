#pragma once

#include "Hazel/Geometry/Rectangle.h"
#include "OrthographicCameraInfo.h"

namespace Hazel
{
	class OrthographicCamera
	{
	private:
		OrthographicCameraInfo info;
		glm::mat4 viewMatrix{1.0f};
		glm::mat4 projectionMatrix{1.0f};
		glm::mat4 viewProjectionMatrix{1.0f};

	public:
		OrthographicCamera(const OrthographicCameraInfo &info = {});

		void SetAspectRatio(float aspectRatio);
		void SetZoomLevel(float zoomLevel);
		void SetViewport(float aspectRatio, float zoomLevel);
		void SetPosition(const glm::vec2 &position);
		void SetRotation(float rotation);

		constexpr float GetAspectRatio() const
		{
			return info.AspectRatio;
		}

		constexpr float GetZoomLevel() const
		{
			return info.ZoomLevel;
		}

		constexpr const glm::mat4 &GetViewProjectionMatrix() const
		{
			return viewProjectionMatrix;
		}

		constexpr const glm::vec2 &GetPosition() const
		{
			return info.Position;
		}

		constexpr float GetRotation() const
		{
			return info.Rotation;
		}

	private:
		void RecomputeViewMatrix();
		void RecomputeProjectionMatrix();
		void RecomputeViewProjectionMatrix();
	};
}