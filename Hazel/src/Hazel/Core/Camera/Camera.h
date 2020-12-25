#pragma once

#include "glm/gtc/matrix_transform.hpp"

#include "CameraView.h"
#include "CameraProjection.h"
#include "Hazel/Core/Geometry/Rectangle.h"

namespace Hazel
{
	struct Camera
	{
		Rectangle Viewport;
		glm::mat4 View{1.0f};
		glm::mat4 Projection{1.0f};
		glm::mat4 ViewProjection{1.0f};

		void RecomputeViewProjection()
		{
			ViewProjection = CameraView::GetViewProjectionMatrix(View, Projection);
		}

		glm::vec3 GetWorldPosition(const glm::vec2 &screenPosition) const
		{
			return glm::unProject(
				glm::vec3(screenPosition, 0.0f),
				View,
				Projection,
				CameraView::GetProjectionViewport(Viewport));
		}

		glm::vec2 GetScreenPosition(const glm::vec3 &worldPosition) const
		{
			return glm::project(
				worldPosition,
				View,
				Projection,
				CameraView::GetProjectionViewport(Viewport));
		}
	};
}