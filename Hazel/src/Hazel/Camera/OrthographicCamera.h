#pragma once

#include "Hazel/Geometry/Rectangle.h"
#include "Hazel/Geometry/Viewport.h"
#include "Hazel/Geometry/Transform.h"

namespace Hazel
{
	class OrthographicCamera
	{
	private:
		Viewport viewport;
		Transform transform;
		glm::mat4 viewProjectionMatrix{1.0f};

	public:
		OrthographicCamera(float aspectRatio);

		void SetAspectRatio(float aspectRatio);
		void SetZoomLevel(float zoomLevel);
		void SetViewport(float aspectRatio, float zoomLevel);
		void SetPosition(const glm::vec2 &position);
		void SetRotation(float rotation);

		constexpr glm::vec2 GetPosition() const
		{
			return transform.Position;
		}

		inline float GetRotation() const
		{
			return transform.Angle;
		}

		constexpr float GetAspectRatio() const
		{
			return viewport.AspectRatio;
		}

		constexpr float GetZoomLevel() const
		{
			return viewport.ZoomLevel;
		}

		constexpr Rectangle GetViewport() const
		{
			return viewport.ToRectangle();
		}

		constexpr const glm::mat4 &GetViewProjectionMatrix() const
		{
			return viewProjectionMatrix;
		}

	private:
		void RecomputeViewProjectionMatrix();
	};
}