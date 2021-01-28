#pragma once

#include "glm/gtc/matrix_transform.hpp"

#include "Hazel/Core/Geometry/Rectangle.h"
#include "CameraView.h"
#include "CameraProjection.h"

namespace Hazel
{
	class Camera
	{
	private:
		Rectangle viewport;
		glm::vec3 position{0.0f};
		glm::mat4 view{1.0f};
		glm::mat4 projection{1.0f};
		glm::mat4 viewProjection{1.0f};

	public:
		const Rectangle &GetViewport() const
		{
			return viewport;
		}

		void SetViewport(const Rectangle &viewport)
		{
			this->viewport = viewport;
		}

		const glm::mat4 &GetViewProjection() const
		{
			return viewProjection;
		}

		void SetViewProjection(const CameraProjection *projection, const Transform *transform)
		{
			if (transform)
			{
				position = transform->Translation;
				view = CameraView::GetViewMatrix(*transform);
			}
			else
			{
				position = glm::vec3(0.0f);
				view = glm::mat4(1.0f);
			}
			this->projection = projection ? projection->ToMatrix() : glm::mat4(1.0f);
			viewProjection = this->projection * view;
		}

		glm::vec3 GetWorldPosition(const glm::vec2 &screenPosition) const
		{
			return glm::unProject(
				glm::vec3(screenPosition, 0.0f),
				view,
				projection,
				CameraView::GetProjectionViewport(viewport));
		}

		glm::vec2 GetScreenPosition(const glm::vec3 &worldPosition) const
		{
			return glm::project(
				worldPosition,
				view,
				projection,
				CameraView::GetProjectionViewport(viewport));
		}
	};
}